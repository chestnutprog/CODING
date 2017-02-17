#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<char> r;
string a;
int n;char k,c;int t;
int main(){
    ios::sync_with_stdio(0);
    cin>>a;
    cin>>n;
    for(int i=0;i<(int)a.length();i++)r.insert(i,a[i]);
    //cout<<r;
    while(n--){
        cin>>k;
        if(k!='Q'){
            cin>>c>>t;
            r.insert(t-1,c);
        }else{
            cin>>t;
            cout<<r[t-1]<<endl;
        }
    }
}