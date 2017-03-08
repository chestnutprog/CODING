#include<bits/stdc++.h>
using namespace std;
int n;
int mi=0x7fffffff,ma=-1,mim=1,mam=1;
int t;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t==mi)mim++;
        if(t==ma)mam++;
        if(t<mi)mim=1,mi=t;
        if(t>ma)mam=1,ma=t;
    }
    cout<<n-mam-(ma!=mi?mim:0);
}