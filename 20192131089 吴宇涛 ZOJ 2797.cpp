#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=110;
//�ڽӾ��� 
int g[N][N];
double dist[N];
bool st[N];
//���ذ�dijkstra�㷨 
void dijkstra() {
	memset(dist,0,sizeof dist);
	dist[1]=100;
	for(int i=0; i<n; i++) {
		int t=-1;
		for(int j=1; j<=n; j++) {
			if(!st[j]&&(t==-1||dist[t]<dist[j]))
				t=j;
		}
		st[t]=true;
		for(int j=1; j<=n; j++)
			dist[j]=max(dist[j],dist[t]*g[t][j]*0.01);
	}
	printf("%.6lf percent\n",dist[n]);
}
int main() {
	while(cin>>n,n) {
		memset(g,0,sizeof g);
		memset(st,0,sizeof st);
		for(int i=1; i<=n; i++) g[i][i]=100;
		cin>>m;
		while(m--) {
			int a,b,c;
			cin>>a>>b>>c;
			g[a][b]=g[b][a]=c;//����ͼ 
		}
		dijkstra();
	}
	return 0;
}
