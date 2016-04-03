#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,dp[100010],a[100010],dp2[100010],ansa,ansb,s;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)dp[i]=max(dp[i-1]+a[i],a[i]),ansa=max(ansa,dp[i]);
	for(int i=1;i<=n;i++)dp2[i]=min(dp2[i-1]+a[i],a[i]),ansb=min(ansb,dp2[i]);
	for(int i=1;i<=n;i++)s+=a[i];
	printf("%d",max(ansa,s-ansb));
} 
