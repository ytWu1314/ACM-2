#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n;
struct Node{
	int a,b;
	double w;
	bool operator <(const Node &r)
	{
		return w<r.w;
	}
}node[N];
int p[N];
double X[N],Y[N];
//路径压缩 寻找祖先
int Find(int x)
{
	if(x!=p[x]) p[x]=Find(p[x]);
	return p[x];
}
int main()
{
	int Case=0;
	while(cin>>n,n)
	{
		int cnt=0;
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>X[i]>>Y[i];
		}
		for(int i=1;i<=n;i++)
		p[i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				node[cnt++]={i,j,sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]))};	
			}
		}
		sort(node,node+cnt);//按照边权值升序排序
		for(int i=0;i<cnt;i++)
		{
			int a=node[i].a,b=node[i].b;
			a=Find(a),b=Find(b);
			if(a!=b)
			{
				if(Find(1)==Find(2)) 
				//如果已经 Freddy Frog 到 Fiona Frog 的路径已经连通则直接跳出 
				break;
				 
				p[a]=b;//合并操作
				ans=max(ans,node[i].w);
			}
		}
		printf("Scenario #%d\n",++Case);
		printf("Frog Distance = %.3lf\n\n",ans);
	}
	return 0;
}
