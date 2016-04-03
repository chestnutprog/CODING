#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans,a[30010],d[30010],S[30010];
#define INF 0x7f7f7f7f
void init()
{
	for(int i = 1; i <=n; i++) S[i] = INF;
	memset(d, 0, sizeof(d));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	for(int i = 1; i <= n; i++)
	{
		int x = 1, y = i;
		int pos = upper_bound(S, S+i, a[i]) - S; 
		d[i] = pos;
		S[d[i]] = min(S[d[i]], a[i]);
		ans = max(ans, d[i]);
	}
	int ansa=ans;
	reverse(a+1,a+n+1);
	init();
	for(int i = 1; i <= n; i++)
	{
		int x = 1, y = i;
		int pos = upper_bound(S, S+i, a[i]) - S; 
		d[i] = pos;
		S[d[i]] = min(S[d[i]], a[i]);
		ans = max(ans, d[i]);
	}
	printf("%d",n-max(ansa,ans));
}
