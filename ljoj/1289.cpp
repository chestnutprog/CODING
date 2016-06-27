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
int n;int a[1010];int l,r;long long ans;
int main(){
    scanf("%d",&n);
    F1(i,n)scanf("%d",&a[i]);
    int l=1;r=n;
    F1(i,n){
      if(a[l]<a[r])ans+=a[l++]*i;else ans+=a[r--]*i;
    }
    cout<<ans;
}
