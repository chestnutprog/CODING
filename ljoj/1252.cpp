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
int p[30],dp[20010];
int n,v;
int main(){
    scanf("%d%d",&v,&n);
    F0(i,n)scanf("%d",&p[i]);
    F0(i,n)
      for(int j=v-p[i];j>=0;j--)
      dp[j+p[i]] = max(dp[j+p[i]],dp[j]+p[i]);
    printf("%d",v-dp[v]);
}
