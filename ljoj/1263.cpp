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
int n;
int dp[101][2010];int a[101];int sum[101];
int main(){
    scanf("%d",&n);
    F1(i,n)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    F1(i,n)
    F1(j,sum[i]+2){
      if(j-a[i]>=0)dp[i+1][j-a[i]]=max(dp[i+1][j-a[i]],dp[i][j]+a[i]);
      dp[i+1][j+a[i]]=max(dp[i+1][j+a[i]],dp[i][j]+a[i]);
    }
    printf("%d",dp[n+1][0]/2);
}
