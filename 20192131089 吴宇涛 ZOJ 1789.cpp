#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int p[N];
int a[N];
int n,m;
//·��ѹ����Ѱ������ 
int find(int x) {
	if(p[x]!=x) p[x]=find(p[x]);
	return p[x];
}
int main() {
	while(cin>>n>>m,n||m) {
		int cnt=0;
		//��ʼ�� 
		for(int i=0; i<=n; i++)
			p[i]=i;
		for(int i=0; i<m; i++) {
			int x;
			cin>>x;
			int r;
			for(int i=0; i<x; i++) {
				cin>>a[i];
				r=a[0];
				p[find(a[i])]=find(r);
			}
		}
		for(int i=0; i<=n; i++) {
			if(find(i)==find(0))
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;

}
