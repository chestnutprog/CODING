#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge{
	int in,out;
}p[100010];
int ans[100010];
int main()
{
	int n,a,b,count=0; 
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d %d",&a,&b);
		p[a].in++;
		p[b].out++;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i].in+p[i].out>3) 
		{
			printf("%d",0);
			return 0;	
		}
		if(p[i].in+p[i].out==3) continue;
		count++;
		ans[count]=i;
	}
	sort(ans+1,ans+count+1);
	printf("%d\n",count);
	for(int i=1;i<=count;i++) printf("%d ",ans[i]);
}

