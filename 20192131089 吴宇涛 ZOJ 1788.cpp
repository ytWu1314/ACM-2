#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=520;
int n,m;
char g[N][N];
//�ķ������νṹ 
typedef struct Tree {
	char val[3];
	Tree *son[4];
} tree;
tree *root;
Tree *dfs(int l,int r,int len) {
	tree *temp=new tree;
	if(len==1) {
		temp->val[0]='0';
		temp->val[1]=g[l][r];
		temp->val[2]=0;
		return temp;
	}
	
	//�ݹ齨�� 
	len/=2;
	temp->son[0]=dfs(l,r,len);
	temp->son[1]=dfs(l,r+len,len);
	temp->son[2]=dfs(l+len,r,len);
	temp->son[3]=dfs(l+len,r+len,len);

	//�ж��Ƿ�Ϊȫ0����ȫ1�� 
	bool can_union=true;
	for(int i=1; i<4; i++) {
		if(strcmp(temp->son[0]->val,temp->son[i]->val)!=0) {
			can_union=false;
			break;
		}
	}
	//�����ȫ1�����ȫ0�� 
	if(can_union) {
		strcpy(temp->val,temp->son[0]->val);
		for(int i=0; i<4; i++) {
			delete temp->son[i]; //ɾ���ӽڵ� 
			temp->son[i]=NULL; //Ҷ�ӽڵ�û���ӽڵ� 
		}
	} else {
		strcpy(temp->val,"1");
	}
	return temp;
}
//��α��� 
string bfs() {
	string s="";
	tree* cur;
	queue<tree*> q;
	q.push(root);
	while(q.size()) {
		cur=q.front();
		q.pop();
		s+=cur->val;
		//�����ǰ�ڵ����ӽڵ� 
		if(!(cur->son[0]==0))
			for(int i=0; i<4; i++)
				q.push(cur->son[i]);
	}
	return s;
}
//2����ת10���� 
int turn(string s) {
	int res=0;
	reverse(s.begin(),s.end());
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='1')
			res+=1<<i;
	}
	return res;
}
int main() {
	cin>>n;
	while(n--) {
		cin>>m;
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				cin>>g[i][j];

		root=dfs(0,0,m);
		string s=bfs();
		int ans=turn(s);
		if(ans==0) {
			cout<<0<<endl;
			continue;
		}
		vector<int> a;
		//10����ת16���� 
		while(ans) {
			a.push_back(ans%16);
			ans/=16;
		}
		for(int i=a.size()-1; i>=0; i--) {
			if(a[i]<10) cout<<a[i];
			else if(a[i]==10) cout<<'A';
			else if(a[i]==11) cout<<'B';
			else if(a[i]==12) cout<<'C';
			else if(a[i]==13) cout<<'D';
			else if(a[i]==14) cout<<'E';
			else cout<<'F';
		}
		cout<<endl;
	}
	return 0;

}
