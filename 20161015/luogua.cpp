#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)
using namespace std;
int n,m,now,t,tt;
long long p[100010],a[100010],b[100010],c[100010];
int o[100010];
long long ans;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>now;
	F1(i,m-1){
		cin>>t;
		tt=t;
		if(now>tt)swap(now,tt);
		o[now]++;o[tt]--;
		now=t;
	}
	now=0;
	F1(i,n-1){
		cin>>a[i]>>b[i]>>c[i];
		now+=o[i];
		ans+=min(a[i]*now,b[i]*now+c[i]);
	}
	cout<<ans<<endl;
}