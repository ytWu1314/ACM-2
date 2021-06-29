#include<iostream>
#include<cstring>
using namespace std;
const int N=110;
char g[N][N];
int n;

//����ģ��������Ҫ������
int h[N],e[N],ne[N],idx;
int st[N];
int match[N];
int col[N][N];
//�ӱߺ���
void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//ƥ���㷨
bool find(int x) {
	//�������ĳ���
	for(int i=h[x]; i!=-1; i=ne[i]) {
		int j=e[i];
		if(st[j]) continue;
		st[j]=true;
		if(!match[j]||find(match[j])) 
		{
			match[j]=x;
			return true;
		}
	}
	return false;
}
int main() {
	while(cin>>n,n) {
		//��ʼ���ڽӱ� ƥ������
		memset(h,-1,sizeof h);
		idx=0;
		memset(match,0,sizeof match);
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin>>g[i][j];
			}
		}
		
		//Ԥ�������ͼ�������ߵĵ�
		int cnt_col=1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(g[j][i]!='X') col[j][i]=cnt_col;
				else if(g[j-1][i]!='X') cnt_col++;
			}
			cnt_col++;
		}
		int cnt_row=cnt_col;
		cnt_col++;
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(g[i][j]!='X') add(col[i][j],cnt_col);
				else if(g[i][j-1]!='X')cnt_col++;
			}
			cnt_col++;
		}
//      ���Ե�ʱ��		
//		for(int i=1;i<=cnt_row;i++)
//		{
//			for(int j=h[i];j!=-1;j=ne[j])
//			cout<<e[j]<<" ";
//			cout<<endl;
//		}
		int ans=0;
		
		//��ߵ�ÿһ����ȥѯ���ұߵ�һ����
		for(int i=1; i<=cnt_row; i++) {
			memset(st,false,sizeof st);
			if(find(i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

