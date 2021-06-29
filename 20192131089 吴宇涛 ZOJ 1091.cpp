#include<bits/stdc++.h>
using namespace std;
const int N=100;
typedef pair<int,int> pii;
//ƫ�������� 
int dx[]= {-2,-2,-1,-1,1,1,2,2},dy[]= {-1,1,-2,2,-2,2,-1,1};
string str1,str2;
int sx,sy,ex,ey;
//����㵽�յ������ 
int d[N][N]; 
void bfs(int X,int Y) {
	queue<pii> q;
	q.push({X,Y});
	d[X][Y]=0;
	if(X==ex&&Y==ey) return ;
	//����ģ�� 
	while(q.size()) {
		
		auto t=q.front();
		q.pop();
		for(int i=0; i<8; i++) {
			int x=t.first+dx[i];
			int y=t.second+dy[i];
			//�ж��Ƿ񲻻�Խ�� 
			if (x >= 0 && x < 8 && y >= 0 && y < 8  && !d[x][y]) {
				
				q.push({x, y});
				d[x][y]=d[t.first][t.second]+1;
			}
		}
	}
}
int main() {
	while(cin>>str1>>str2) {
		memset(d,0,sizeof d); //�ǵó�ʼ�� 
		sx=str1[0]-'a';
		sy=str1[1]-'0'-1;
		ex=str2[0]-'a';
		ey=str2[1]-'0'-1;
		bfs(sx,sy);
		cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<d[ex][ey]<<" knight moves."<<endl;
	}

}
