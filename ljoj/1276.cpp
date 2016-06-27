#include<cstdio>
#define LL long long
const int mx[4]={1,2,2,1};
const int my[4]={2,1,-1,-2};
LL f[60][60];
int n,m,x1,x2,y1,y2;
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    f[x1][y1]=1;
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        for (int k=0;k<4;k++)
          {
            int nx=i+mx[k];
            int ny=j+my[k];
            if (nx<1||nx>n||ny<1||ny>m)continue;
            f[nx][ny]+=f[i][j];
          }
    printf("%lld\n",f[x2][y2]);
}
