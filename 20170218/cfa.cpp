#include<bits/stdc++.h>
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
int n;
set<int> s,t;int a;int maxp;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;maxp=n+1;
    for(int i=1;i<=n;i++)t.insert(i);
    for(int i=1;i<=n;i++){
        cin>>a;
        s.insert(a);
        while(!s.empty()&&*s.rbegin()==*t.rbegin()){
            //for(auto x=s.rbegin();x!=s.rend();x++)
            cout<<*s.rbegin()<<' ',t.erase(*s.rbegin()),s.erase(*s.rbegin());
            //s.clear();
        }
        cout<<endl;
    }
}
//1 2 3 5 4