#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[310][310];
int main()
{
	int m,n,k;
	scanf("%d %d %d",&n,&m,&k);
	memset(a,0x7f,sizeof(a));
	for(int i=1,x,y,z;i<=m;i++) 
	{
		scanf("%d %d %d",&x,&y,&z);
		if(a[x][y]>z)	a[x][y]=z;
	}
	for (int x=1;x<=n;x++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            	a[i][j]=min(max(a[i][x],a[x][j]),a[i][j]);	
	for(int i=1,s,t;i<=k;i++)
    {
        scanf("%d%d",&s,&t);
        if(a[s][t]<0x3f)
        printf("%d\n",a[s][t]);
        else printf("%d\n",-1);
    }
    return 0;
				
}
