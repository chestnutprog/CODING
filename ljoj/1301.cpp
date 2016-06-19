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
int a[5000010];int n,mod;
int main(){
  scanf("%d%d",&n,&mod);
  a[1]=1;
  F(i,2,n/2+1)a[i]=(a[i-1]+a[i/2])%mod;
  printf("%d", a[n/2]);

}
