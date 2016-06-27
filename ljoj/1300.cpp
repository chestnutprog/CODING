#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=506;
int dis[maxn][maxn],f[maxn][maxn],d[maxn];
int n,m;
int qiu(int,int);
int ma()
{
	memset(f,0x7f,sizeof(f));
	f[0][0]=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=qiu(i,j);
		//	printf("i===%d,j==%d  %d\n",i,j,dis[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m&&j<=i;j++)
		{
			//f[i][j]=0x7ffffff;
			for(int k=0;k<=i-1;k++)
			{
				f[i][j]=min(f[i][j],f[k][j-1]+dis[k+1][i]);
			}
		}
	}
	printf("%d",f[n][m]);
	return 0;
}
int qiu(int s,int t )
{
	int mid=(s+t)/2;
	int tot=0;
	for(int i=s;i<mid;i++)
	{
		tot+=d[mid]-d[i];
	}
	for(int i=mid+1;i<=t;i++)
	{
		tot+=d[i]-d[mid];
	}
	return tot;
}
int hh=ma();
int main()
{
	;
}
