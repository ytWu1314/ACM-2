#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1100;
const int M=2e4+10;
int dist[N];
bool st[N];  
int h[M],e[M],ne[M],cnt[M],idx;
ll w[M];
int n,m;
//邻接表添加边 
void add(int a,int b,ll x)
{
	e[idx]=b,w[idx]=x,ne[idx]=h[a],h[a]=idx++;
}
ll spfa()
{
	memset(dist,0x3f,sizeof dist);
	memset(cnt,0,sizeof cnt);
	memset(st,false,sizeof st);
	//n为超源点 
	dist[n]=0;
	st[n]=false;
	queue<int> q;
	q.push(n);
	while(q.size())
	{
		int t=q.front();
		q.pop();
		st[t]=false;
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i];
			if(dist[j]>dist[t]+w[i])
			{
				dist[j]=dist[t]+w[i];//松弛操作
				//判断是否出现了负环
				cnt[j]=cnt[t]+1;
				if(cnt[j]>=n+1) return -1;
				if(!st[j])
				{
					st[j]=true;
					q.push(j);//加入队列
				}
			}
		}
	}
	return dist[0];
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		//初始化邻接表 
		idx=0;
		memset(h,-1,sizeof h);
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			//统一转化为最短路求法 
			add(i-1,i,x);
			add(i,i-1,0);
		}
		for(int i=1;i<=m;i++)
		{
			int a,b;
			ll x;
			cin>>a>>b>>x;
			add(b,a-1,-x);
		}
		ll ans=spfa();
		if(ans==-1) puts("Bad Estimations");
		else cout<<-ans<<endl;
	}
	return 0;
}
