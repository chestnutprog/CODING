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
int p[110];
long long dp[10010];
int n,v,ans;
int main(){
    scanf("%d%d",&n,&v);
    F1(i,n)scanf("%d",&p[i]);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    	for(int j=p[i];j<=v;j++)
    		dp[j] += dp[j-p[i]];
    printf("%lld",dp[v]);
}
