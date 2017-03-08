#include<bits/stdc++.h>
using namespace std;
int k;
string n;
int ans,zeroc;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=n.size()-1;i>=0&&zeroc<k;i--){
        if(n[i]=='0')zeroc++;else ans++;
    }
    cout<<min((int)n.size()-1,zeroc==k?ans:0x7fffffff);
}