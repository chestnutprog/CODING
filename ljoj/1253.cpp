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
int p[110],nu[110];
bool dp[4000010];
int n,v,ans;
int main(){
    scanf("%d",&n);
    F0(i,n)scanf("%d%d",&nu[i],&p[i]),v+=p[i]*nu[i];
    dp[0]=1;
    F0(i,n)
      F0(k,nu[i])
      for(int j=v;j>=p[i];j--)
      if(dp[j-p[i]])dp[j]=1;
      //dp[j+p[i]] = max(dp[j+p[i]],dp[j]+p[i]);
    //printf("%d",v-dp[v]);
    F1(i,v)if(dp[i])ans++;
    printf("Total=%d",ans);
}
