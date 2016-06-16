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
int c[1000][1000];
int dp[1000][1000];
int n;
int main(){
    scanf("%d",&n);
    F0(i,n)
      F0(j,i+1)
        scanf("%d",&c[i][j]);
    for(int i=n-1;i>=0;i--)
      F0(j,i+1)
        dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+c[i][j];
    printf("%d",dp[0][0]);
}
