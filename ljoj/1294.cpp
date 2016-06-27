#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <iomanip>
#include <sstream>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define INF 0x7fffffff
int n;char a[1010],b[1010];
int now;
int main(){
  scanf("%d%s%s",&n,a,b);
  F0(i,n){
    if(abs(now+=a[i]-b[i])>1){printf("Accepted!" );return 0;}
  }
  printf("Impossible!");
}
