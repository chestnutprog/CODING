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
int dp[3010];
pair<int,int > p[2010];
int n;
int main(){
    scanf("%d",&n);
    F0(i,n)scanf("%d%d",&p[i].second,&p[i].first);
    sort(p,p+n);
    F0(i,n){
      for(int j=p[i].second-1;j>=0;j--)
      dp[p[i].first] = max(dp[p[i].first],dp[j]+p[i].first-p[i].second+1);
      for(int j=p[i].second;j<=3000;j++)dp[j]=max(dp[j],dp[j-1]);
    }
    printf("%d",dp[p[n-1].first]);
}
