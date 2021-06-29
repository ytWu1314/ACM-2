#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;
string s;
//r d l u
int dx[]= {0,1,0,-1},dy[]= {1,0,-1,0};
//字符串转化成数字
int turn(string s) {
	int res=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='x') res*=10;//把x当成0
		else res=res*10+s[i]-'0';
	}
	return res;
}
//不同数据类型映射
unordered_map<int,bool> st; //开st数组太浪费空间了
unordered_map<int,string> path;
void bfs() {
	//初始化字符串
	string start="12345678x";
	string dir="rdlu"; //与 dx dy 数组一一对应
	queue<pair<string,string>> q; //pair结构体 first存放字符串的状态 second存放走的方向
	q.push({start,""});
	st[turn(start)]=true;
	path[turn(start)]="";

	//宽搜模板
	while(q.size()) {
		auto t=q.front();
		q.pop();
		string Str=t.first;

		//将x出现的位置转化成二维坐标
		int w=Str.find('x');
		int x=w/3,y=w%3;

		//四个方向搜索
		for(int i=0; i<4; i++) {
			int a=x+dx[i];
			int b=y+dy[i];
			if(a>=0&&a<3&&b>=0&&b<3) {
				string to=Str;
				swap(to[w],to[a*3+b]);  //交换x和数字的位置
				int num=turn(to);

				//没有搜到的加入队列 继续搜索
				if(!st[num]) {
					st[num]=true; //避免重复搜索
					path[num]=t.second+dir[i];
					q.push({to,path[num]});
				}
			}
		}
	}
}
int main() {
	string S;
	//预处理宽搜，将所有的情况存入st ，path里面 
	bfs();
	//字符串输入处理 
	while(getline(cin,S)) {
		string s; 
		for(int i=0; i<17; i+=2) {
			s+=S[i];
		}
		int res=turn(s);
		
		if(st[res]) {
			string r=path[res];

			//从最终状态走到起始状态
			//两次相反操作既可以把路径输出
			for(int i=r.size()-1; i>=0; i--) {
				if(r[i]=='l') cout<<'r';
				else if(r[i]=='r') cout<<'l';
				else if(r[i]=='u') cout<<'d';
				else cout<<'u';
			}
			cout<<endl;
		} else puts("unsolvable");

	}
	return 0;
}
