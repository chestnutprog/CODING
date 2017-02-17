#include<algorithm>
#include<iostream>
#include<set>
#include<map>
using namespace std;
#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)
set<pair<int,char> > mpx,mpy,mpd,mpu;
int n,x0,y0;
char t1;int t2,t3;
bool ans;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x0>>y0;
    F0(i,n){
        cin>>t1>>t2>>t3;
        if(t2==x0){
            mpx.insert(make_pair(t3,t1));
        }
        if(t3==y0){
            mpy.insert(make_pair(t2,t1));
        }
        if(t3-t2==y0-x0){
            mpu.insert(make_pair(t2,t1));
        }
        if(t3+t2==y0+x0){
            mpd.insert(make_pair(t2,t1));
        }
    }
    set<pair<int,char> >::iterator now;
    now = mpx.lower_bound(make_pair(y0,' '));
    if(now!=mpx.end()){
    ans|=(now->second=='R');
    ans|=(now->second=='Q');
    }
    if(now!=mpx.begin())now=--now;
    if(now!=mpx.end()){
    ans|=(now->second=='R');
    ans|=(now->second=='Q');
}
    now=mpy.lower_bound(make_pair(x0,' '));
    if(now!=mpy.end()){
    ans|=(now->second=='R');
    ans|=(now->second=='Q');
}
    if(now!=mpy.begin())now=--now;
    if(now!=mpy.end()){
    ans|=(now->second=='R');
    ans|=(now->second=='Q');
}
    now=mpu.lower_bound(make_pair(x0,' '));
    if(now!=mpu.end()){
    ans|=(now->second=='B');
    ans|=(now->second=='Q');
}
    if(now!=mpu.begin())now=--now;
    if(now!=mpu.end()){
    ans|=(now->second=='B');
    ans|=(now->second=='Q');
}
    now=mpd.lower_bound(make_pair(x0,' '));
    if(now!=mpd.end()){
    ans|=(now->second=='B');
    ans|=(now->second=='Q');
}
    if(now!=mpd.begin())now=--now;
    if(now!=mpd.end()){
    ans|=(now->second=='B');
    ans|=(now->second=='Q');
}
if(ans)
    cout<<"YES";else cout<<"NO";
}
/*
2
4 2
R 1 1
B 1 5
*/