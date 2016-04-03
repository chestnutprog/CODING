#include<cstdio>
#include<algorithm>
using namespace std;
long long n,t=1,ans,temp[20000010];
int main(){
	temp[1]=1;
	for(int i=1;i<=20000000;i++)temp[i+1]=temp[i]+i;
	scanf("%I64d",&n);
	n=n-*(upper_bound(temp,temp+20000000,n)-1)+1;
	printf("%I64d",n);
}
