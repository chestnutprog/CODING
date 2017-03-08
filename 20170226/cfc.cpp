#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200005],b[200005],t,ans;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];ans+=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t;b[i]=t-a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n-k&&b[i]<0;i++){
        ans+=b[i];
    }
    cout<<ans;
}