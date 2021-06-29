#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	while(getline(cin,a),a!="#") //一行一行的输入可以有空格 
	{
		long long sum=0;
		int n=a.size();
		for(int i=0;i<n;i++)
		{
			if(a[i]!=' ')
			sum+=(a[i]-'A'+1)*(i+1);
		}
		cout<<sum<<endl;
	}
	return 0; 
}
