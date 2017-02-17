#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#define inf 1000000000
#define maxn 500+100
#define maxm 500+100
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define mod 1000000007
using namespace std;
int n,a[110],t;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for1(i,n)cin>>a[i];
    /*
    v.push_back(0);
    for1(i,n)t+=a[i];
    for1(i,n-1){
        if(a[i+1])v.push_back(i);
    }
    v.push_back(n);*/
    v.push_back(0);
    for1(i,n){
        t+=a[i];
        if(t==0&&a[i]!=0){
            v.push_back(i-1);
            t=a[i];
        }
    }
    v.push_back(n);
    if(t==0){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        cout<<v.size()-1<<endl;
        for(vector<int>::iterator x = v.begin();x+1!=v.end();x++){
            cout<<*x+1<<' '<<*(x+1)<<endl;
        }
    }
}

