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
int a[360],dp[200010],mins[360],S[360],d[360];
int n,v,ans,anss,i;
int main(){
        while(scanf("%d",&a[++i])!=EOF);
        n=i;
        F0(i,n)S[i]=INF;
        F1(i,n){
        S[d[i]  = upper_bound(S, S+i, -a[i]) - S ] = min(S[d[i]], -a[i]);
        ans = max(ans, d[i]);
        }
        mins[1]=a[0];dp[0]=1;
        F1(i,n-1){
            F0(j,i)
                if(a[i]<=a[j] && a[i] < mins[dp[j]]){mins[dp[j]] = a[i],dp[i] = anss;break;}
            if(!dp[i])dp[i]=++anss,mins[dp[i]]=a[i];
        }
        printf("%d\n%d",ans,dp[n-1]);
}
