#include<iostream>
#include<cstring>
using namespace std;
const int N=256;
const int M=1e5+10;
int g[N][N];
char s[N][N];
int n,m;
int ans1,ans2;
int idx;
struct Tree {
	int son0,son1,son2,son3;
} tr[M];
//引入计数器ans1,ans2在深搜的时候计数
int dfs(int l,int r,int len) {
	int temp=ans2;
	ans1++,ans2++;
	if(len==1) return g[l][r];
	int t=len/2;
	int son0=dfs(l,r,t);
	int son1=dfs(l,r+t,t);
	int son2=dfs(l+t,r,t);
	int son3=dfs(l+t,r+t,t);
	//如果为全0 则不可分 
	if(son0==0&&son1==0&&son2==0&&son3==0) {
		ans1-=4,ans2-=4;
		return 0;
	}
	//如果为全1 则不可分 
	if(son0==1&&son1==1&&son2==1&&son3==1) {
		ans1-=4,ans2-=4;
		return 1;
	}
	//idx从1开始 
	for(int i=2; i<=idx; i++) {
		if(tr[i].son0==son0 &&tr[i].son1==son1&&tr[i].son2==son2&&tr[i].son3==son3) {
			ans2=temp;
			return i;
		}
	}
	tr[++idx]= {son0,son1,son2,son3};
	return idx;
}
int main() {
	while(cin>>n>>m) {
		if(n==0&&m==0)
			return 0;
		memset(g,0,sizeof g);//记得初始化
		ans1=0,ans2=0;
		idx=1;
		for(int i=0; i<n; i++) {
			cin>>s[i];
			for(int j=0; j<m; j++)
				g[i][j]=s[i][j]-'0';
		}
		
		//转化为大于最大边的2次幂 
		int len=1;
		int L=max(n,m);
		while(len<L) len<<=1;
		//cout<<len<<endl;
		dfs(0,0,len);
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
