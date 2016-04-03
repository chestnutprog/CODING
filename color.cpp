#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,p[100010],c[100010],ci[100010],f[100010];
bool vi[100010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&ci[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	int x =sqrt(n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++) 
			if(c[i]==ci[(i+j)%(n+1)+1])
			f[i]=min(f[i],i);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	if(ans==0x3f3f3f3f)printf("%d",-1);
	else printf("%d",ans);
	return 0;
			
}
