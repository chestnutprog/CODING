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
int n,m;
int a[301][301];
int dp[301][301];
int main(){
  scanf("%d%d",&n,&m);
  F0(i,n)
    F0(j,m)
      scanf("%d",&a[i][j]);
  F1(i,n)
    F1(j,m)
      for(int k=j;k>=0;k--)
        dp[i][j]=max(dp[i][j],dp[i-1][j-k]+a[i-1][k-1]);
    printf("%d",dp[n][m]);
}
