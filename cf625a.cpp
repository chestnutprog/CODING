#include<cstdio>
long long n,a,b,c,ans;
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
	if(b-c>=a&&b>=a){
		printf("%I64d",n/a);
		return 0;
	}
	long long t=0;
	if(n>=b){
		ans+=t=(n-b)/(b-c);
		n-=(b-c)*t;
	}
	if(n>=b)n-=b,n+=c,ans++;
	ans+=n/a;
	printf("%I64d",ans);
}
