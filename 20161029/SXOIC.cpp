#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define F0(i, n) for (int i = 0; i < (n); i++)
#define F1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
int n, m, v, t, k, a, b, c, tot,al;
int ans;
/*
struct e {
    int go, next, v;
} edge[10010];
void add(int x, int y, int c){
    edge[++tot] = (e){y, head[x], c}; head[x] = tot;
    edge[++tot] = (e){x, head[y], c}; head[y] = tot;
}
*/
struct p {
    int x, y, v;
    bool operator <(p a) const {
        return v < a.v;
    }
} edges[10010];
int fa[310], head[310];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> v >> t >> k;
    F1(i, m){
        cin >> a >> b >> c; edges[i] = (p){a, b, c};
    }
    F1(i,n)fa[i]=i;
    sort(edges+1,edges+1+m);
    int i = 1;
    while(al!=n-1){
        p now = edges[i];
        a = getfa(now.x);b = getfa(now.y);
        if(a!=b){
            fa[a]=b;
            al++;
            ans+=now.v;
        }
        i++;
    }
    cout<<k+ans*t*v;
}