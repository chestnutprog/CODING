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
int n,a[110];
int main(){
  scanf("%d",&n);
  F1(i,n)scanf("%d",&a[i]);
  F1(i,n)
    F(j,i,n-1){
      if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
        printf("%d %d\n",j,j+1);
      }
    }
}
