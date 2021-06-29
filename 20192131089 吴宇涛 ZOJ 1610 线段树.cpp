#include<iostream>
#include<cstring>
using namespace std;
const int N=8000;
struct Node{
	int l;
	int r;
	int color;
}tr[4*N];
int ans[N+1];
int cnt[N+1];
int n;
void build(int u,int l,int r)
{
	tr[u]={l,r,-1};
	if(l==r) return ;
	int mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
}
void modify(int u,int l,int r,int c)
{
	if(tr[u].l>r||tr[u].r<l) return ;
	if(tr[u].l>=l&&tr[u].r<=r) {
		tr[u].color=c;
		return ;
	}
	
	//˵��������֮ǰ��Ⱦ��ɫ
	if(tr[u].color!=-1)
	{
		tr[u<<1].color=tr[u<<1|1].color=tr[u].color;
	}
	//����ɫ���´������޸��Լ�����ɫΪ-1
	 
	tr[u].color=-1;
	modify(u<<1,l,r,c);
	modify(u<<1|1,l,r,c);
}
//�����ڵ����Ϣ���ݸ��ӽڵ� 
void pushdown(int u)
{
	//�ҵ���Ҷ�ӽڵ� 
	if(tr[u].l==tr[u].r)
	{
		ans[tr[u].r]=tr[u].color;
		return; 
	}	
	if(tr[u].color!=-1) tr[u<<1].color=tr[u<<1|1].color=tr[u].color;
	pushdown(u<<1),pushdown(u<<1|1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n)
	{
		build(1,1,N);
		memset(ans,-1,sizeof ans);
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<n;i++)
		{
			int l,r,color;
			cin>>l>>r>>color;
			//�޸�һ���������ɫ ������Ҫl+1 
			modify(1,l+1,r,color);
		}
		pushdown(1);
		for(int i=1;i<=N;i++)
		{
			cnt[ans[i]]++;
			int j=i+1;
			while(ans[j]==ans[i]) j++;
			i=j-1;
		}
		for(int i=0;i<=N;i++)
		{
			if(cnt[i])
			{
				cout<<i<<" "<<cnt[i]<<endl;
			}
		}
		cout<<endl;
	}
}
