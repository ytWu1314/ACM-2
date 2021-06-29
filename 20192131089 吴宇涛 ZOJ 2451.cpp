#include<iostream>
using namespace std;
const int N=5e4+10;
const int inf=1e9;
int n,m;
//线段树一般开四倍数组 
struct Node{
	int l,r;
	int Min; //需要求最小值则存取最小值 
}tr[4*N];
void build(int u,int l,int r)
{
	tr[u]={l,r,inf}; //初始化 
	if(l==r)
	{
		int v;
		if(r==1)v=0;
		else v=inf;
		tr[u].Min=v;
		return ;
	}
	int mid=l+r>>1;
	//递归建树 
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tr[u].Min=min(tr[u<<1].Min,tr[u<<1|1].Min);
}
int query(int u,int l,int r)
{
	// 树中节点，已经被完全包含在[l, r]中了
	if(tr[u].l>=l&&tr[u].r<=r) return tr[u].Min;
	int mid=tr[u].l+tr[u].r>>1;
	int v=inf;
	
	//去左子树找 
	if(l<=mid) v=query(u<<1,l,r);
	//去右子树找 
	if(r>mid) v=min(v,query(u<<1|1,l,r));
	return v;
}
void modify(int u,int p,int x)
{
	if(tr[u].l>p||tr[u].r<p) return ;
	if(tr[u].l==p&&tr[u].r==p){
		tr[u].Min=min(tr[u].Min,x);
		return ;
	}
	modify(u<<1,p,x),modify(u<<1|1,p,x);
	tr[u].Min=min(tr[u<<1].Min,tr[u<<1|1].Min); 
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		build(1,1,n); //建树 
		int ans=inf;
		while(m--)
		{
			int l;
			int r;
			scanf("%d %d",&l,&r);
			int x=query(1,l,r-1); //点线段树，区间r-1 
			if(x==inf) continue;
			modify(1,r,x+1);
			if(r==n) ans=min(ans,x+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
