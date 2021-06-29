#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=2e6+10;
int n,m,k;
struct Node {
	int a,b;
	double w;
	//重载符号方便排序
	bool operator< (const Node&r) {
		return w<r.w;
	}
} node[N];
//坐标数组
double X[N],Y[N];
int p[N];
//并查集状态压缩
int Find(int x) {
	if(x!=p[x]) p[x]=Find(p[x]);
	return p[x];
}
int main() {
	cin>>n;
	while(n--) {
		int cnt=0;
		int edge_cnt=0;
		
		cin>>m;
		for(int i=1; i<=m; i++) p[i]=i;
		
		for(int i=1; i<=m; i++) {
			cin>>X[i]>>Y[i];
		}
		
		cin>>k;
		for(int i=0; i<k; i++) {
			int a,b;
			cin>>a>>b;
			a=Find(a),b=Find(b);
			if(a!=b)
				p[a]=b;
			edge_cnt++;
		}
		//边集结构体数据存储
		for(int i=1; i<=m; i++) {
			for(int j=i+1; j<=m; j++) {
				node[cnt++]= {i,j,sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]))};
			}
		}
		sort(node,node+cnt);
		
		for(int i=0; i<cnt; i++) {
			int a=node[i].a,b=node[i].b;
			if(Find(a)!=Find(b)) {
				cout<<node[i].a<<" "<<node[i].b<<endl;
				p[Find(a)]=Find(b);
				//if(edge_cnt==m-1)
				//break;
			}
		}
		if(n!=0)puts("");
	}
	
}

