#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 500+100
#define maxm 500+100
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define mod 1000000007
using namespace std;
int n;
ll a[100005];
ll now,ts,tf,t;
int waited;
ll anst,answ;
int main(){
    ios::sync_with_stdio(0);
    cin>>ts>>tf>>t;now=ts;anst=ts;answ=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n!=0)anst=min(a[1]-1,ts); else anst=ts;
    for(int i=1;i<=n;){
        while(i<=n&&now>=a[i]){
            waited++;i++;
        }
        if(waited*t+ts>=tf)break;
        if((ts+waited*t-now)<answ){answ=waited*t-now;anst=now;}
        if(now==waited*t+ts){cout<<now;return 0;}
        now=min(a[i],waited*t+ts);
    }
    if(n*t+ts<tf){cout<<tf-1;return 0;}
    cout<<anst;
}
/*
10 20 2
4
10 11 12 13


*/