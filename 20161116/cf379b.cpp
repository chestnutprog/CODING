#include<algorithm>
#include<iostream>
using namespace std;
#define F0(i,n) for(int i=0;i<(n);i++)
int a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    cout<<min(a,min(c,d))*256+(min(a-min(a,min(c,d)),b))*32;
}