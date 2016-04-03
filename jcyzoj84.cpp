#include<cstdio>
#include<deque>
using namespace std;
#define MAXN (100010)
deque<int> q;
int n,k;
long long a[MAXN],f[MAXN],sum,ans=0x7fffffffffffffff;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);sum+=a[i];
	}
	q.push_back(0);
	for(int i=1;i<=n;i++){
		while(i-k-1>q.front())q.pop_front();
		f[i] = f[q.front()] + a[i];
		while(f[q.back()] >= f[i]) q.pop_back();
		q.push_back(i);
		if(i+k>=n) ans = min(ans,f[i]);
	}
	printf("%lld",sum - ans);
}
