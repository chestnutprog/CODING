#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int xi[9]={0,-2,-1,1,2,2,1,-1,-2},
    yi[9]={0,1,2,2,1,-1,-2,-2,-1};
unsigned long long a[21][21],n,m,x,y,i,j;
bool map[21][21];
int main()
{
    cin>>n>>m>>x>>y;
    for(int i=1;i<=8;i++)
    {
        if(xi[i]+x>=0&&xi[i]+x<=20&&yi[i]+y>=0&&yi[i]+y<=20)
            map[xi[i]+x][yi[i]+y]=1;
    }
    map[x][y]=1;
    for(i=0;i<=20;i++)
    {if(map[0][i]==1){a[0][i]=0;break;}a[0][i]=1;}
    for(i=0;i<=20;i++)
    {if(map[i][0]==1){a[i][0]=0;break;}a[i][0]=1;}
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
        if(map[i][j]==1)a[i][j]=0;
        else a[i][j]=a[i-1][j]+a[i][j-1];
        }
    cout<<a[n][m];
    return 0;
}
