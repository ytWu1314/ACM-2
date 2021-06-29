#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+10;
int n,m;
int p[N],num[N];
char op[2];
//并查集初始化 
void init()
{
    for(int i=1;i<=n;i++)
        p[i]=i,num[i]=1;
}
//寻找祖先，路径压缩 
int Find(int x)
{
    if(x!=p[x]) p[x]=Find(p[x]);
    return p[x];
}
int main()
{
    bool flag=1;int cnt=1;
    while(cin>>n>>m)
    {
        init();
        if(!flag) puts("");
        flag=0;
        printf("Case %d:\n",cnt++);
        while(m--)
        {
            cin>>op; 
            if(op[0]=='M')
            {
                int a,b;
                cin>>a>>b;
                a=Find(a),b=Find(b);
                if(a!=b)
                {
                    p[a]=b; //合并操作 
                    num[b]+=num[a];
                }
            }
            else if(op[0]=='Q') {
                {
                    int q;
                    cin>>q;
                    q=Find(q); //询问操作 
                    cout<<num[q]<<endl;
                }
            }
        }
    }
}
