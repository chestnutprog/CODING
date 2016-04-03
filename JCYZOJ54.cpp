#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define mod 1000000007
#define ll long long
#define inf (1LL<<60)
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,mx;
ll S,ans=inf;
int l[200005],r[200005];
int w[200005],v[200005];
ll sum[200005],cnt[200005];
ll cal(int W)
{
	ll tmp=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		cnt[i]=cnt[i-1];	
		if(w[i]>=W)
		{
			sum[i]+=v[i];
			cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		tmp+=(cnt[r[i]]-cnt[l[i]-1])*(sum[r[i]]-sum[l[i]-1]);
	}
	return tmp;
}
int main()
{
	n=read();m=read();S=read();
	for(int i=1;i<=n;i++)
		w[i]=read(),v[i]=read();
	for(int i=1;i<=n;i++)
		mx=max(mx,w[i]);
	for(int i=1;i<=m;i++)
		l[i]=read(),r[i]=read();
	int l=0,r=mx+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		ll t=cal(mid);
		ans=min(ans,abs(t-S));
		if(t<S)r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
