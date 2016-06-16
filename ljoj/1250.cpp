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
int a[100000];
int S[100000];
int d[100000];
int n,ans;
int main(){
    scanf("%d",&n);
    F1(i,n)
        scanf("%d",&a[i]);
    F0(i,n)S[i]=INF;
    F1(i,n){
    S[d[i]  = upper_bound(S, S+i, a[i]-1) - S ] = min(S[d[i]], a[i]);
    ans = max(ans, d[i]);
  }
    printf("%d",ans+1);
}
