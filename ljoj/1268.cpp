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
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define INF 0x7fffffff
long long f[1001][1001];
long long a[1001];
int n,i,j,k,l,x;
long long mn=LLONG_MAX;

int main(){
    cin>>n;a[0]=1000000;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    memset(f,127/3,sizeof(f));
    F1(i,2*n)f[i][i]=0;
    for(l=1;l<=n;l++)
        for(i=1;i<=2*n-l;i++)
        {
            j=i+l;
            for(int k=i;k<j;k++)
                f[i][j]=min(f[i][k]+f[k+1][j]+ a[i-1]*a[k]*a[j],f[i][j]);
        }
    for(i=1;i<=n;i++)
        mn=min(mn,f[i][i+n-2]);
             cout<<mn;
    return 0;
}
