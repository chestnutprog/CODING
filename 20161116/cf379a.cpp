#include<algorithm>
#include<iostream>
using namespace std;
#define F0(i,n) for(int i=0;i<(n);i++)
int n;char c;
int a,b;
int main(){
    cin>>n;
    F0(i,n){
        cin>>c;
        if(c=='A')a++;else b++;
    }
    if(a==b)cout<<"Friendship";
    else if(a>b) cout<<"Anton";else
    cout<<"Danik";
}