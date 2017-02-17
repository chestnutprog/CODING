#include<iostream>
#include<cstdio>
#define F1(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n;
int a[100010];
int b[100010];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    F1(i,n)cin>>a[i];
    F1(i,n)cout<<a[i]+a[i+1]<<' ';
}