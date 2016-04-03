#include<cstdio>
#include<algorithm>
using namespace std;
int s[1010],ans[1010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+1+n);
	for(int i=1;i<=(n+1)/2;i++)ans[i*2-1]=s[i];
	for(int i=(n+1)/2+1,j=1;i<=n;i++,j+=2)ans[n-j+1-(n%2)]=s[i];
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}

