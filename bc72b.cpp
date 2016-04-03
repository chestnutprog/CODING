#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define xls(i) x[t[i].l]
#define xrs(i) x[t[i].r]
#define yls(i) y[t[i].l]
#define yrs(i) y[t[i].r]
long long x[1000010],y[1000010];
using namespace std;
struct St{
	int l,r;
}t[4000010];
inline void pushup(int i){
	long long manhadun1=abs(xls(i<<1)-xrs(i<<1))+abs(yls(i<<1)-yrs(i<<1));
	long long manhadun2=abs(xls(i<<1|1)-xrs(i<<1|1))+abs(yls(i<<1|1)-yrs(i<<1|1));
	long long manhadun3=abs(xls(i<<1)-xls(i<<1|1))+abs(yls(i<<1)-yls(i<<1|1));
	long long manhadun4=abs(xls(i<<1)-xrs(i<<1|1))+abs(yls(i<<1)-yrs(i<<1|1));
	long long manhadun5=abs(xrs(i<<1)-xls(i<<1|1))+abs(yrs(i<<1)-yls(i<<1|1));
	long long manhadun6=abs(xrs(i<<1)-xrs(i<<1|1))+abs(yrs(i<<1)-yrs(i<<1|1));
	long long manhadun=max(manhadun1,max(manhadun2,max(manhadun3,max(manhadun4,max(manhadun5,manhadun6)))));
	if(manhadun==manhadun1){t[i].l=t[i<<1].l;t[i].r=t[i<<1].r;}
	if(manhadun==manhadun2){t[i].l=t[i<<1|1].l;t[i].r=t[i<<1|1].r;}
	if(manhadun==manhadun3){t[i].l=t[i<<1].l;t[i].r=t[i<<1|1].l;}
	if(manhadun==manhadun4){t[i].l=t[i<<1].l;t[i].r=t[i<<1|1].r;}
	if(manhadun==manhadun5){t[i].l=t[i<<1].r;t[i].r=t[i<<1|1].l;}
	if(manhadun==manhadun6){t[i].l=t[i<<1].r;t[i].r=t[i<<1|1].r;}
}
void build(int l,int r,int i){
	if(l==r){t[i].l=t[i].r=l;return;}
	int mid = (l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	pushup(i);
}
long long seed;int T,n;
inline long long rand(long long l, long long r) {
	static long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>n>>seed;
		for (int i = 0; i < n; i++)
		x[i] = rand(-1000000000, 1000000000),
		y[i] = rand(-1000000000, 1000000000);
		build(0,n-1,1);
		cout<<abs(xls(1)-xrs(1))+abs(yls(1)-yrs(1))<<endl;
	}
}

