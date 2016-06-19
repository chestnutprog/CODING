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
#define INF 0x7fffffff
int a[100010], head[100010], tot,dp[100010];
int size[100010];
int n, ans, t1, t2;
struct edge {
    int go, next, v;
} e[100010];
void add(int x, int y, int v){
    e[++tot] = (edge){y, head[x], v}; head[x] = tot;
}
int dfs(int x,int y,int v){
  dp[x]=max(dp[x],dp[y]+v);int ans = 0;
  for(int i=head[x];i;i=e[i].next){
    ans+=dfs(e[i].go,x,e[i].v);
  }
  size[y]+=size[x];
  if(dp[x]>a[x])return size[x];
  return ans;
}
int main(){
    scanf("%d", &n);
    F1(i, n) scanf("%d", &a[i]),size[i]=1;
    F(i, 2, n){
        scanf("%d%d", &t1, &t2);
        add(t1, i, t2);
    }
    printf("%d",dfs(1,1,0));
    //scanf("%d");
}
