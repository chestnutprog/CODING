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
int p[500],dp[510][510],c[500],p2[500];
int n,v,s,v2;
int main(){
    scanf("%d%d%d",&v,&v2,&n);
    F0(i,n)scanf("%d%d%d",&c[i],&p[i],&p2[i]),s+=c[i];
    F0(i,n)
    for(int k=v2-p2[i];k>=0;k--)
      for(int j=v-p[i];j>=0;j--)
      dp[j+p[i]][k+p2[i]] = max(dp[j+p[i]][k+p2[i]],dp[j][k]+c[i]);
    printf("%d",dp[v][v2]);
}
