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
#define MAXN 100010
int a[MAXN],b[MAXN],loc[MAXN];
int S[MAXN],d[MAXN];
int n,m,ans;
int main(){
    scanf("%d",&n);
    F0(i,n)scanf("%d",&a[i]);
    F0(i,n)scanf("%d",&b[i]);
    F0(i,n)loc[b[i]]=i;
    F0(i,n)b[i]=loc[a[i]];
    F0(i,n)S[i]=INF;
    F0(i,n){
    S[d[i]  = upper_bound(S, S+i, b[i]) - S ] = min(S[d[i]], b[i]);
    ans = max(ans, d[i]);
  }
    printf("%d",ans+1);
}
