#include<iostream>
#include<map>
using namespace std;
//使用map可以很容易的解决这道题 
map<int,int> mp;
int sum=0;
int n;
int main() {
	map<int,int> ::iterator it ;//迭代器 
	while(scanf("%d",&n),n) {
		if(n==1) {
			int x,p;
			scanf("%d%d",&x,&p);
			mp[p]=x;
			sum++;
		}
		if(n==2) {
			if(sum==0) {
				printf("0\n");
			} else {
				it=mp.end();
				it--;
				printf("%d\n",it->second);
				mp.erase(it);
				sum--;
			}
		}
		if(n==3) {
			if(sum==0) {
				printf("0\n");
			} else {
				it=mp.begin();
				printf("%d\n",it->second);
				mp.erase(it);
				sum--;
			}
		}
	}
	return 0;
}
