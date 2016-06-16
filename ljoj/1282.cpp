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
int a[100000],b[100000];
int S[100000];
int d[100000],d2[100000];
int n,ans=0x7ffffff;
int main(){
    scanf("%d",&n);
    F1(i,n)
        scanf("%d",&a[i]),b[n-i+1]=a[i];
    F0(i,n)S[i]=INF;
    F1(i,n){S[d[i]  = upper_bound(S, S+i, a[i]-1) - S ] = min(S[d[i]], a[i]);}
    F0(i,n)S[i]=INF;
    F1(i,n){S[d2[i]  = upper_bound(S, S+i, b[i]-1) - S ] = min(S[d2[i]], b[i]);}
    F1(i,n)ans=min(ans,n-d[i]-d2[n-i+1]-1);
    printf("%d",ans);
    //F1(i,n)printf("%d ",d[i] );
    //F1(i,n)printf("%d ",d2[i] );
}
