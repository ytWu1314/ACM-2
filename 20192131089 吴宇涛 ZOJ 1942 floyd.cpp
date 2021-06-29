#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=300; //点数的数据范围   2<=n<=200
int n;
double X[N],Y[N];
double g[N][N];
void floyd() {
	//最外层循环是中介点 k
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				//Floyd类似动态规划的思想
				//找出连通路中最大边的最小值
				g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
			}
		}
	}
}
int main() {
	int Case=0;
	while(cin>>n,n) {
		for(int i=1; i<=n; i++) {
			cin>>X[i]>>Y[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				//无向图邻接矩阵需要注意
				g[j][i]=g[i][j]=sqrt((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]));
			}
		}
		floyd();
		printf("Scenario #%d\n",++Case);
		printf("Frog Distance = %.3lf\n\n",g[1][2]);
	}
	return 0;
}
