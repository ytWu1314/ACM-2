#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
const int M=1e5+10;
//�߼��ṹ������ 
struct Node {
	int a;
	int b;
	double w;
	//���ط��� �������� 
	bool operator <(const Node &r) {
		return w<r.w;
	}
}node[M];
double X[M],Y[M];
int p[M];
//·��ѹ����Ѱ������ 
int Find(int x) {
	if(x!=p[x]) p[x]=Find(p[x]);
	return p[x];
}
int main() {
	int Case=0;
	while(cin>>n,n) {
		int cnt=0;
		for(int i=1; i<=n; i++)p[i]=i;
		double ans=0;
		for(int i=1; i<=n; i++) {
			cin>>X[i]>>Y[i];
		}

		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				node[cnt++]= {i,j,sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]))};
			}
		}
		sort(node,node+cnt); //����		
		int edge_cnt=0;
		for(int i=0; i<cnt; i++) {
			int a=node[i].a,b=node[i].b;
			if(Find(a)!=Find(b)) {
				p[Find(a)]=Find(b);
				ans+=node[i].w;
				//cout<<a<<" "<<b<<" "<<ans<<endl;
				edge_cnt++;
				if(edge_cnt==n-1)break; //��������С������  ֱ������ 
			}
		}
		if(Case) puts("");
		printf("Case #%d:\n",++Case);
		printf("The minimal distance is: %.2lf\n",ans);
	}
	return 0;
}
