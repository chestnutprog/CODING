/*noip 2014 联合权值*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200000+5000;
ll maxw,tot;
vector<int> g[maxn];
int w[maxn];

void dfs(int x,int fa)
{
if(g[x].size()==1)return; //叶子节点
vector<int> tmpw;
tmpw.clear();
tmpw.push_back(w[fa]); //若x为根节点，则此权值为0，不会影响结果
int r1,r2; r1=fa;r2=0;
ll tmptot=w[fa];
for(int i=0;i<g[x].size();i++)
{
int& y=g[x][i];
if(y==fa)continue;
tmpw.push_back(w[y]);
if(w[y]>w[r1]){r2=r1; r1=y;}
else if(w[y]>w[r2])r2=y;
tmptot+=w[y];
dfs(y,x);
}
for(int i=0;i<tmpw.size();i++){
ll unionw=(tmptot-tmpw[i])*tmpw[i]; //每对权值已被计算两次，不用再乘2
tot+=unionw; tot%=10007;
}
maxw=max(maxw,(ll)w[r1]*w[r2]);
};

int main()
{
// freopen("test.in","r",stdin);
int n;
cin>>n;
for(int i=1;i<=n-1;i++){
int u,v;
scanf("%d%d",&u,&v);
g[u].push_back(v);
g[v].push_back(u);
}
g[1].push_back(0);//为了减少特判
for(int i=1;i<=n;i++)scanf("%d",&w[i]);
dfs(1,0);
cout<<maxw<<" "<<tot<<endl;
return 0;
}
