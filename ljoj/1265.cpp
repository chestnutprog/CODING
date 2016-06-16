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
pair<int,int> s[10000];
int a,b,n,S[10000],d[10000],ans;
int main(){
  scanf("%d",&n);
  F1(i,n){
    scanf("%d%d",&a,&b);
    s[i]=make_pair(a,b);
  }
  sort(s+1,s+n+1);
  //F0(i,n)printf("%d ",s[i].second);
  F0(i,n)S[i]=INF;
  F1(i,n){
  S[d[i]  = upper_bound(S, S+i, s[i].second-1) - S ] = min(S[d[i]], s[i].second);
  ans = max(ans, d[i]);
}
  printf("%d",ans+1);
}
