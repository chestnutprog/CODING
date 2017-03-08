#include <bits/stdc++.h>
using namespace std;
long long a[1005];
int n,M;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    a[0]=1;a[1]=1;a[2]=0;a[3]=0;
    while(cin>>n){
        cin>>M;
        for(int i=4;i<=1001;i++)a[i]=((i+1)*a[i-1]%M-(i-2)*a[i-2]%M-(i-5)*a[i-3]%M+(i-3)*a[i-4]%M+M)%M;
        cout<<a[n]<<endl;
    }

}