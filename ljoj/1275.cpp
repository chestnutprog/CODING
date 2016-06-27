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
long long m,n;
int main(){
  //cin>>n>>m;
  scanf("%lld,%lld",&m,&n);
  if(n>m)swap(n,m);
  cout<<(3*m-n+1)*n*(n+1)/6<<","<<m*n*(m+1)*(n+1)/4-(3*m-n+1)*n*(n+1)/6;
}
