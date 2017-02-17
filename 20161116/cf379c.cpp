#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)
long long n,m,k,ans;
long long x,s;
struct t{
    long long cost,v;
    bool operator < (t b)const{
        return cost<b.cost;
    }
}a[200010],b[200010];
set<t> sa,sb;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    cin>>x>>s;
    ans=x*n;
    F0(i,m)cin>>a[i].v;
    F0(i,m)cin>>a[i].cost;
    F0(i,k)cin>>b[i].v;
    F0(i,k)cin>>b[i].cost;
    sort(a,a+m);
    sa.insert(a[0]);
    F1(i,m-1){
        if(sa.end()->cost==a[i].cost){
            if(sa.end()->v>a[i].v){
                sa.erase(sa.end());
                sa.insert(a[i]);
            }
        }else{
        //    if(sa.end()->v>a[i].v){
                sa.insert(a[i]);
        //    }
        }
    }
    F0(i,k){
        sb.insert(b[i]);
    }
    for(set<t>::iterator now = sa.begin();now!=sa.end();now++){
        set<t>::iterator nowb = --(sb.upper_bound((t){s-now->cost,0}));
        if(nowb->cost+now->cost<=s){
            ans=min(now->v*max(n-nowb->v,0LL),ans);
        }else{
            if(now->cost<=s)ans=min(now->v*n,ans);
        }

    }
    set<t>::iterator nowb = --(sb.upper_bound((t){s,0}));
    if(nowb->cost<=s){
        ans=min(x*max(n-nowb->v,0LL),ans);
    }
    cout<<ans;
}
/*
90 1 1
10 99
2
99
77
99
*/