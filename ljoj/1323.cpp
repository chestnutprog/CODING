#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long f[101][101];
int sum[101];
int i,j,t,n,m,l,r,k,z,y,x;
int main()
{
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
        scanf("%d",&t);
        sum[i]=sum[i-1]+t;
        f[i][0]=sum[i];
    }
    for (i=1;i<=n;i++) for (j=1;j<=min(m,i-1);j++) for (k=1;k<i;k++)
    {
        f[i][j]=max(f[i][j],f[k][j-1]*(sum[i]-sum[k]));
    }
    printf("%lld",f[n][m]);
    return 0;
}
