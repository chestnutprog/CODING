#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define maxn 300010
#define INF 0x7fffffff
struct edge{
  int to,next;
}edges[maxn];
int head[maxn];
struct CenterTree{
    int n;
    int ans;
    int siz;
    int son[maxn];
    int res[maxn];
    void dfs(int u,int pa){
        son[u]=1;
        //int res=0;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==pa) continue;
            //if (vis[v]) continue;
            dfs(v,u);
            son[u]+=son[v];
            res[u]=max(res[u],son[v]-1);
        }
        res[u]=max(res[u],n-son[u]);
        if (res[u]<siz){
            ans=u;
            siz=res[u];
        }
    }
    int getCenter(int x){
        ans=0;
        siz=INF;
        dfs(x,-1);
        return ans;
    }
}Cent;
int n,q,tot,t;
int main(){
  scanf("%d%d",&n,&q);
  memset(head,-1,sizeof(head));
  F1(i,n-1){
    scanf("%d",&t);
    edges[++tot]=(edge){i,head[t]};head[t]=tot;
  }
  Cent.siz=INF;
  Cent.dfs(1,-1);
  F1(i,q){
    scanf("%d",&t);
    printf("%d\n",Cent.getCenter(t));
  }
}
