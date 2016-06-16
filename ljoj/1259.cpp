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
int p[110],dp[200010];
int n,v,s;
int main(){
    scanf("%d%d",&v,&n);
    F0(i,n)scanf("%d",&p[i]);
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;//dp[1]=1;
    F0(i,n)
      F0(j,v-p[i]+1)//for(int j=v-p[i];j>=0;j--)
      dp[j+p[i]] = min(dp[j+p[i]],dp[j]+1);
    printf("%d",dp[v]==0x7f7f7f7f?0:dp[v]);
}
