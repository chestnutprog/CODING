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
int a[3010],b[3010];
int dp[3010][3010];
int n,m;
int main(){
    scanf("%d",&n);
    F0(i,n)scanf("%d",&a[i]);
    scanf("%d",&m);
    F0(i,m)scanf("%d",&b[i]);
    F1(i,n)
      F1(j,m)
        if(a[i-1]==b[j-1])
          dp[i][j]=1+dp[i-1][j-1];
        else
          dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    printf("%d",dp[n][m]);

}
