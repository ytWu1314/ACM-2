#include<iostream>
#include<cstring>
using namespace std;
const int N=110;
char g[N][N];
int n;

//数组模拟链表需要的数组
int h[N],e[N],ne[N],idx;
int st[N];
int match[N];
int col[N][N];
//加边函数
void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//匹配算法
bool find(int x) {
	//找这个点的出边
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
		//初始化邻接表 匹配数组
		memset(h,-1,sizeof h);
		idx=0;
		memset(match,0,sizeof match);
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				cin>>g[i][j];
			}
		}
		
		//预处理二分图左右两边的点
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
//      调试的时候看		
//		for(int i=1;i<=cnt_row;i++)
//		{
//			for(int j=h[i];j!=-1;j=ne[j])
//			cout<<e[j]<<" ";
//			cout<<endl;
//		}
		int ans=0;
		
		//左边的每一个点去询问右边的一个点
		for(int i=1; i<=cnt_row; i++) {
			memset(st,false,sizeof st);
			if(find(i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

