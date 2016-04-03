#include <cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
map<int,int> m;
int a[11000],g[1100],s[1100],n,maxs,maxn,tot1,tot2;
long long t,anse;
#define INF 0x7fffffff
#define for1(i,n) for(int i=1;i<=(n);i++)
int d[11000],S[11000];
void init()
{
    for1(i,n) S[i] = INF;
    memset(d, 0, sizeof(d));
}
int main(){
    while(scanf("%d",&n)!=EOF){
    	cin>>t;
    anse=0;
    m.clear();
    for1(i,n){
        scanf("%d",&a[i]);
        m[a[i]]++;
    } 
    if(n*t<=10000){
    	int anss = 0;
		for1(j,t-1)for1(i,n)a[j*n+i]=a[i];
		    for1(i,n*t) S[i] = INF;
    memset(d, 0, sizeof(d));
        for1(i,n*t){
            d[i] = upper_bound(S, S+i, a[i]) - S; 
            S[d[i]] = min(S[d[i]], a[i]);
            anss = max(anss, d[i]);
        }
        cout<<anss<<endl;
        continue;
	}
	
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        int ans=0,anss=0;
        maxn=(*it).first;maxs=(*it).second;
        tot1=0;tot2=0;
        for1(i,n){
            if(a[i]==maxn)g[++tot1]=s[++tot2]=a[i];
            if(a[i]>maxn)g[++tot1]=a[i];
            if(a[i]<maxn)s[++tot2]=a[i];
        } 
        init();
        for1(i,tot1){
            d[i] = upper_bound(S, S+i, g[i]) - S; 
            S[d[i]] = min(S[d[i]], g[i]);
            anss = max(anss, d[i]);
        }
        init();
        for1(i,tot2){
            d[i] = upper_bound(S, S+i, s[i]) - S; 
            S[d[i]] = min(S[d[i]], s[i]);
            ans = max(ans, d[i]);
        }
        anse=max(anse,anss+ans+maxs*(t-2));
    }
    cout<<anse<<endl;
}
    return 0;
}
