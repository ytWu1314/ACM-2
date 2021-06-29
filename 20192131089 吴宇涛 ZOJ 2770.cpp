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
//�ڽӱ���ӱ� 
void add(int a,int b,ll x)
{
	e[idx]=b,w[idx]=x,ne[idx]=h[a],h[a]=idx++;
}
ll spfa()
{
	memset(dist,0x3f,sizeof dist);
	memset(cnt,0,sizeof cnt);
	memset(st,false,sizeof st);
	//nΪ��Դ�� 
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
				dist[j]=dist[t]+w[i];//�ɳڲ���
				//�ж��Ƿ�����˸���
				cnt[j]=cnt[t]+1;
				if(cnt[j]>=n+1) return -1;
				if(!st[j])
				{
					st[j]=true;
					q.push(j);//�������
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
		//��ʼ���ڽӱ� 
		idx=0;
		memset(h,-1,sizeof h);
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			//ͳһת��Ϊ���·�� 
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
