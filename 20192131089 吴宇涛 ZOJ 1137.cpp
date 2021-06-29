#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+10;
bool st[N];
int e[N],ne[N],h[N],idx;
int match[N];
int n;
//邻接表加边
void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//匈牙利算法
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
		//初始化
		memset(h,-1,sizeof h);
		memset(match,0,sizeof match);
		idx=0;
		for(int i=0; i<n; i++) {
			int id,x;
			scanf("%d: (%d)", &id, &x); //输入格式要注意 
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
		cout<<n-cnt/2<<endl; //最大独立集=点数-最大匹配（这里要除以2，因为遍历的时候是两部分都算进去了） 
	}

}
