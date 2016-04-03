#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long f[18][1<<16],a[21],n,k;
long long ans;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)f[i][1<<i]=1;
	for(int i=0;i < ( 1<<n );i++) 
		for(int j=0;j < n;j++)
			if(i & (1 << j))
				for(int t=0;t < n;t++)
					if(!(i&(1<<t))&&abs(a[j]-a[t])>k)
						f[t][i | (1 << t)]+=f[j][i];
	for(int i=0;i < n;i++) ans+=f[i][(1<<n)-1];
	 cout<<ans;
	 return 0;
}

