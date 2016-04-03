#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;return a;}
    ll d = exgcd(b,a%b,x,y);
    swap(x,y);y=y-x*(a/b);
    return d;
}
int main(){
    ll a,b,x=0,y=0;
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<((x%b)+b)%b;
}
