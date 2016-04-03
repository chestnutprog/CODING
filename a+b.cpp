#include<cstdio>
int n,ans,t;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&t),ans+=t;
	printf("%d",ans);
}
