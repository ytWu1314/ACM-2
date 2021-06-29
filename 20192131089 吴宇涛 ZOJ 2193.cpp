#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1100;
int n;
string s;
int a[20];
//链式前向星——邻接表 
int e[N],ne[N],h[N],idx;
int d[N];
void add(int a,int b) {
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
//预处理初始图 
vector<int> g[20]= {{1},{1,2},{2,3},{3},{1,4},{1,2,4,5},{2,3,5,6},{3,6},{4,7},{4,5,7,8},{5,6,8,9},{6,9},{7},{7,8},{8,9},{9}};
//拓扑排序判环 
bool topsort() {
	int cnt=0;
	queue<int> q;
	for(int i=1; i<=9; i++)
		if(!d[i]) q.push(i);
	while(q.size()) {
		int t=q.front();
		cnt++;
		q.pop();
		for(int i=h[t]; i!=-1; i=ne[i]) {
			int j=e[i];
			d[j]--;
			if(!d[j]) {
				q.push(j);
			}
		}
	}
	//cout<<cnt<<endl;
	return cnt==9; //判断是否出现了环 大于9说明存在环 
}
int main() {
	while(cin>>s) {
		if(s=="ENDOFINPUT") return 0;
		memset(h,-1,sizeof h);
		idx=0;
		memset(d,0,sizeof d);
		for(int i=0; i<16; i++) {
			cin>>a[i];
		}
		for(int i=0; i<16; i++) {
			for(int j=0; j<g[i].size(); j++) {
				if(a[i]!=g[i][j])
				{
					add(a[i],g[i][j]);
					d[g[i][j]]++;
				}
				//cout<<g[i][j]<<" ";	
			}
		}
		//for(int i=1;i<=9;i++)
		//cout<<d[i]<<" ";
		//cout<<endl;
		if(topsort())
			puts("THESE WINDOWS ARE CLEAN");
		else puts("THESE WINDOWS ARE BROKEN");
		cin>>s;
	}
	return 0;
}
