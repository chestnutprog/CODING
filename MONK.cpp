#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int h[6000];
vector<int> G[6000];
int boss[6000];
int f[60000][2];
void dfs(int k)
{
    for(int j=0;j<G[k].size();j++)
    {
        int i=G[k][j];
        dfs(i);
        f[k][0]+=max(f[i][0],f[i][1]);
        f[k][1]+=f[i][0];
    }
    f[k][1]+=h[k];
}
int main()
{
    scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        memset(boss,0,sizeof(boss));
        memset(f,0,sizeof(f));
        int x,y;
        while(scanf("%d%d",&x,&y)==2,x||y)
        {
            G[y].push_back(x);
            boss[x]=y;
        }
        for(int i=1;i<=n;i++)
        {
            if(boss[i]==0)//根节点
            {
                dfs(i);//树形DP
                printf("%d\n",max(f[i][0],f[i][1]));
                break;
            }
        }
    return 0;
}
