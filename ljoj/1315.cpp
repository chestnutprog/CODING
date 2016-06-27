#include<stdio.h>
#include<stdlib.h>
int a[101][101]={0},w[10000][2]={0},v[10000]={0},x,y;
int co()
{
	int i,n,j,m,k,max=0,l,t1,t2;
	scanf("%d%d%d",&m,&n,&k);
	for(i=1;i<=k;i++)
	{
	  scanf("%d%d%d",&w[i][0],&w[i][1],&v[i]);
	  max+=v[i];
	}
	for(i=0;i<=m;i++)
	  for(j=0;j<=n;j++)
	    a[i][j]=max;
	a[0][0]=0;
	for(i=1;i<=k;i++)
	{
	  for(j=m;j>=0;j--)
	  {
	    for(l=n;l>=0;l--)
	    {
		  t1=j>w[i][0]?j-w[i][0]:0;
		  t2=l>w[i][1]?l-w[i][1]:0;
	      if(a[j][l]>a[t1][t2]+v[i])
	        a[j][l]=a[t1][t2]+v[i];
	    }
	  }
	}
	printf("%d",a[m][n]);
	return 0;
}
int t=co();
int main(){;}
