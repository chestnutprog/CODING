#include <cstdio>
#include <algorithm>
#include<set>
#include<cmath>
using namespace std;
int n;
int a[110];
int l,r;
int ans;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    scanf("%d", &n);
    F1(i, n){
      scanf("%d", &a[i]);
      if(a[i]==1)l=i;
      if(a[i]==n)r=i;
    }
    printf("%d ",max(max(r-1,n-r),max(l-1,n-l)));
    if(l>r)swap(l,r);
    printf("%d ",r-l+max(l-1,n-r));
}
