#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
char s[N][N];
int MAX;
bool judge(int row,int col)
{
	//������ǰ�����һ��
	for(int i=row-1;i>=0;i--)
	{
		if(s[i][col]=='@') return 0;
		if(s[i][col]=='X') break;
	}
	//������ǰ�����һ��
	for(int i=col-1;i>=0;i--)
	{
		if(s[row][i]=='@') return 0;
		if(s[row][i]=='X') break;
	}
	return 1;
}
void dfs(int pos,int cnt)
{
	if(pos==n*n)
	{
		if(MAX<cnt)
		{
			MAX=cnt;
			return ;
		}
	}
	else {
		//��ǰ���ֵӳ��Ϊ��ά����
		int row=pos/n;
		int col=pos%n;
		//�ж��Ƿ���Է���
		if(s[row][col]=='.'&&judge(row,col))
		{
			s[row][col]='@';
			dfs(pos+1,cnt+1);
			s[row][col]='.'; //�ָ��ֳ�
		}
		//���ܷ�����������һ����ֵ��
		dfs(pos+1,cnt);
	}
}
int main()
{	
	while(cin>>n,n)
	{
		MAX=0;
		for(int i=0;i<n;i++)
		cin>>s[i];
		dfs(0,0);	
		cout<<MAX<<endl;
	}
	return 0;	
}

