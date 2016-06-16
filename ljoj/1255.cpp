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
int p[30],dp[20010],T[4];
int v,ans,s,n;
int main(){
    F0(i,4)scanf("%d",&T[i]);
    F0(pp,4){
      s=0;memset(dp,0,sizeof(dp));
      n=T[pp];
      F0(i,n)scanf("%d",&p[i]),s+=p[i];
      v=s/2;
      F0(i,n)
        for(int j=v-p[i];j>=0;j--)
        dp[j+p[i]] = max(dp[j+p[i]],dp[j]+p[i]);
        ans+=s-dp[v];
  }
  printf("%d",ans);
}
