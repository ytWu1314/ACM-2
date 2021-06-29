#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;
string s;
//r d l u
int dx[]= {0,1,0,-1},dy[]= {1,0,-1,0};
//�ַ���ת��������
int turn(string s) {
	int res=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='x') res*=10;//��x����0
		else res=res*10+s[i]-'0';
	}
	return res;
}
//��ͬ��������ӳ��
unordered_map<int,bool> st; //��st����̫�˷ѿռ���
unordered_map<int,string> path;
void bfs() {
	//��ʼ���ַ���
	string start="12345678x";
	string dir="rdlu"; //�� dx dy ����һһ��Ӧ
	queue<pair<string,string>> q; //pair�ṹ�� first����ַ�����״̬ second����ߵķ���
	q.push({start,""});
	st[turn(start)]=true;
	path[turn(start)]="";

	//����ģ��
	while(q.size()) {
		auto t=q.front();
		q.pop();
		string Str=t.first;

		//��x���ֵ�λ��ת���ɶ�ά����
		int w=Str.find('x');
		int x=w/3,y=w%3;

		//�ĸ���������
		for(int i=0; i<4; i++) {
			int a=x+dx[i];
			int b=y+dy[i];
			if(a>=0&&a<3&&b>=0&&b<3) {
				string to=Str;
				swap(to[w],to[a*3+b]);  //����x�����ֵ�λ��
				int num=turn(to);

				//û���ѵ��ļ������ ��������
				if(!st[num]) {
					st[num]=true; //�����ظ�����
					path[num]=t.second+dir[i];
					q.push({to,path[num]});
				}
			}
		}
	}
}
int main() {
	string S;
	//Ԥ������ѣ������е��������st ��path���� 
	bfs();
	//�ַ������봦�� 
	while(getline(cin,S)) {
		string s; 
		for(int i=0; i<17; i+=2) {
			s+=S[i];
		}
		int res=turn(s);
		
		if(st[res]) {
			string r=path[res];

			//������״̬�ߵ���ʼ״̬
			//�����෴�����ȿ��԰�·�����
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
