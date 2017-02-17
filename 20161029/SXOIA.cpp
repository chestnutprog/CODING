#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)
using namespace std;
typedef long long LL;
#define mod 100003
LL m,n;
LL power(LL base,LL pow){
    LL res=1;
    while(pow){
        if(pow&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        pow>>=1;
    }
    return res;
}
int main(){
    cin>>m>>n;
    //m%=mod;n%=mod;
    cout<<(power(m,n)-(m*power(m-1,n-1))%mod+mod)%mod;
}