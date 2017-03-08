#include<bits/stdc++.h>
using namespace std;
string a,b,t1,t2;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin>>a>>b;
    cin>>n;
    cout<<a<<' '<<b<<endl;
    for(int i=1;i<=n;i++){
        cin>>t1>>t2;
        if(a==t1)a=t2;else b=t2;
        cout<<a<<' '<<b<<endl;
    }
}