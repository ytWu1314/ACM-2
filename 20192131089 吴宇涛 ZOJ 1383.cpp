#include<bits/stdc++.h>
using namespace std;
int t,n;
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		bool flag=false;
		int cnt=0;
		while(n) {
			//二进制操作 
			if(n&1) {
				if(!flag) {
					cout<<cnt;
					flag=true;
				} else cout<<" "<<cnt;
			}
			n>>=1;
			cnt++;
		}
		cout<<endl;
	}
	return 0; 
}
