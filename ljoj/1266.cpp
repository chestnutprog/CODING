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
int main()
{
    int n,m;
    int a[101]={0};
    int mx[101][101][10],mn[101][101][10];
    int ans1=0,ans2=10000;
    cin>>n>>m;
    memset(mx,0,sizeof(mx));
    for(int i=1;i<=2*n;i++)
       for(int j=1;j<=2*n;j++)
          for(int k=1;k<=m;k++)
            mn[i][j][k]=10000;
    for(int i=1;i<=2*n;i++)
            if(i<=n){cin>>a[i];a[i]+=a[i-1];}
            else a[i]=a[n]+a[i-n];
    for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
                  {
                  mx[i][j][1]=a[j]-a[i];
                  mx[i][j][1]%=10;
                  while(mx[i][j][1]<0)mx[i][j][1]+=10;
                  mn[i][j][1]=mx[i][j][1];
                  }
    for(int i=2;i<=m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j;k<=2*n;k++)
                for(int p=j+1;p<k;p++)
                {
                mx[j][k][i]=max(mx[j][k][i],mx[j][p][i-1]*mx[p][k][1]);
                mn[j][k][i]=min(mn[j][k][i],mn[j][p][i-1]*mn[p][k][1]);
                }
    for(int i=1;i<=n;i++)
    {
            ans1=max(ans1,mx[i][i+n][m]);
            ans2=min(ans2,mn[i][i+n][m]);
            }
    cout<<ans2<<endl<<ans1;
    //system("pause");
    return 0;
}
