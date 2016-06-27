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
int p[11],dp[200010],vp[11];
int n=10,v;
int main(){
    F0(i,10)scanf("%d",&vp[i]),p[i]=i+1;
    scanf("%d",&v);
    memset(dp,127,sizeof dp);
    dp[0]=0;
    F0(i,n)
      for(int j=0;j<=v-p[i];j++)
      dp[j+p[i]] = min(dp[j+p[i]],dp[j]+vp[i]);
    printf("%d",dp[v]);
}
