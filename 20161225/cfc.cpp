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
set<pair<int,int> > point;
#define disten (abs(nowx-lax)+abs(nowy-lay))
int n;
int nowx,nowy;
int lax,lay,llx,lly;
int ladis;
char p;
int ans;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for1(i,n){
        cin>>p;
        switch (p) {
            case 'L':nowx--;
            break;
            case 'R':nowx++;
            break;
            case 'U':nowy++;
            break;
            case 'D':nowy--;
            break;
        }
        if(disten<ladis){
            point.insert(make_pair(llx,lly));
            ans++;
            lax=llx;lay=lly;
        }
        llx=nowx;lly=nowy;
        ladis=disten;
    }
    point.insert(make_pair(nowx,nowy));
    //cout<<point.size();
    cout<<ans+1;
}

