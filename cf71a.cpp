#include<string>
#include<iostream>
using namespace std;
int n;
string t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t.length()<=10)cout<<t<<endl;else cout<<t[0]<<t.length()-2<<t[t.length()-1]<<endl;
    }
}
