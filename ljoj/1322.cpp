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
int n;
double a[110],dp[110][2];
int main(){
   scanf("%d",&n);
   F1(i,n)scanf("%lf",&a[i]);
   dp[1][0]=100;
   F1(i,n)
     F1(j,i){
       dp[i][0]=max(dp[i][0],max(dp[j][0],dp[j][1]/a[j]));
       dp[i][1]=max(dp[i][1],max(dp[j][1],dp[j][0]*a[j]));
     }
  printf("%.2lf",dp[n][0]);
}
