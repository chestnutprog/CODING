#include<bits/stdc++.h>
using namespace std;
unordered_set<long long> s;
long long n,k,t,a[100001],ans,p,sum[100001];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    s.insert(1);s.insert(k);p=k;
    for(int i=1;i<=17;i++)s.insert(k=k*p);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1;int r=n;
    while(l<=r){
        t=sum[r]-sum[l];
    }
    cout<<ans;
}
