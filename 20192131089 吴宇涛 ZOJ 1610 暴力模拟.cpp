#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=8005;
int color[N],cnt[N];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		//初始化 
		memset(color,-1,sizeof color);
		memset(cnt,0,sizeof cnt);
		
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			//颜色覆盖 
			for(int j=x;j<y;j++)
			color[j]=z;
		}
		if(color[0]!=-1)
		cnt[color[0]]++;
		
		for(int i=1;i<N;i++)
		{
			if(color[i]!=-1&&color[i]!=color[i-1])
			cnt[color[i]]++;
		}
		//遍历整个cnt数组 
		for(int i=0;i<N;i++)
		if(cnt[i])
		printf("%d %d\n",i,cnt[i]);
		puts("");
	}
	return 0;
}
