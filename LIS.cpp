#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
using namespace std;
int n,ans,a[30010],d[30010],S[30010];
#define INF 0x7fffffff
void init()
{
	for0(i,n) S[i] = INF;
	memset(d, 0, sizeof(d));
}
int main()
{
	scanf("%d",&n);
	for0(i,n)scanf("%d",&a[i]);
	init();
	for0(i,n){
		d[i] = lower_bound(S, S+i, a[i]) - S; 
		S[d[i]] = min(S[d[i]], a[i]);
		ans = max(ans, d[i]+1);
	}
	cout<<ans<<endl;
}
