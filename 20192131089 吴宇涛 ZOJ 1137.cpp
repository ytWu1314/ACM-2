#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+10;
bool st[N];
int e[N],ne[N],h[N],idx;
int match[N];
int n;
//�ڽӱ�ӱ�
void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//�������㷨
bool find(int x) {
	for(int i=h[x]; i!=-1; i=ne[i]) {
		int j=e[i];
		if(!st[j]) {
			st[j]=true;
			if(match[j]==0||find(match[j])) {
				match[j]=x;
				return true;
			}
		}
	}
	return false;
}
int main() {
	while(cin>>n) {
		//��ʼ��
		memset(h,-1,sizeof h);
		memset(match,0,sizeof match);
		idx=0;
		for(int i=0; i<n; i++) {
			int id,x;
			scanf("%d: (%d)", &id, &x); //�����ʽҪע�� 
			while(x--) {
				int b;
				cin>>b;
				add(id,b);
			}
		}
		int cnt=0;
		for(int i=0; i<n; i++) {
			memset(st,false,sizeof st);
			if(find(i))
				cnt++;
		}
		cout<<n-cnt/2<<endl; //��������=����-���ƥ�䣨����Ҫ����2����Ϊ������ʱ���������ֶ����ȥ�ˣ� 
	}

}
