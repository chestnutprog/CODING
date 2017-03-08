#include<bits/stdc++.h>
using namespace std;
#define pri pair<int,int>
#define mp(a,b) make_pair(a,b)
#define forbi(x,y) forbid[x+2001][y+2001]
#define vi(x,y) v[x+2001][y+2001]
vector<pri > C,S;
struct task{
    int x,y,time;
}t;
queue<task> q;
string x;
int n,ans=INT_MAX;
int lm=3000,rm=0,um=3000,dm=0;
bitset<6002> forbid[6002],v[6002];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<n;j++){
            if(x[j]=='r'){
                S.push_back(mp(j,i));
                lm=min(lm,j);rm=max(rm,j);
                um=min(um,i);dm=max(dm,i);
            }else if(x[j]=='X'){
                C.push_back(mp(j,i));
            }
        }
    }
#define cx C[i].first
#define cy C[i].second
#define sx S[j].first
#define sy S[j].second
#define s0x S[0].first
#define s0y S[0].second
    for(int i=0;i<(int)C.size();i++){
        for(int j=0;j<(int)S.size();j++){
            forbi(s0x+(cx-sx),s0y+(cy-sy))=1;
        }
    }
    q.push((task){s0x,s0y,1});
    while(!q.empty()){
        t=q.front();q.pop();
        if(vi(t.x,t.y))continue;
        vi(t.x,t.y)=1;
        if(forbi(t.x,t.y))continue;
        if(lm+(t.x-s0x)>=n ||
           rm+(t.x-s0x)<=0 ||
           um+(t.y-s0y)>=n ||
           dm+(t.y-s0y)<=0 ){
            ans=min(ans,t.time);
        }else{
            q.push((task){t.x+1,t.y,t.time+1});
            q.push((task){t.x-1,t.y,t.time+1});
            q.push((task){t.x,t.y+1,t.time+1});
            q.push((task){t.x,t.y-1,t.time+1});
        }
    }
    if(ans==INT_MAX)cout<<"NIE";else cout<<ans;
    //cout<<(ans==INT_MAX?"NIL":ans);
}