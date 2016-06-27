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
long long mn=0;

int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    memset(f,0,sizeof(f));
    //for(i=1;i<=2*n;i++)f[i][i]=1;
    for(l=1;l<=n;l++)
        for(i=1;i<=2*n-l;i++)
        {
            j=i+l;
            for(int k=i;k<j;k++)
                f[i][j]=max(f[i][k]+f[k+1][j]+ a[i]*a[k+1]*a[j+1],f[i][j]);
        }
    for(i=1;i<=n;i++)
        mn=max(mn,f[i][i+n-1]);
             cout<<mn;
    return 0;
}
