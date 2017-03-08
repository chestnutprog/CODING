#include <bits/stdc++.h>
using namespace std;
#define N 500
#define maxn N * 2 + 5
#define maxm 500005
#define ey e[i].go
#define INF 0x7f7f7f7f
#define inf INF
bitset<maxn> v;
int d[maxn], from[maxn];
queue<int> q;
int s, t, mincost, maxflow;
struct edge {
    int from, go, next, v, c;
} e[maxm];
int head[maxn], tot = 1;
ostream& operator ,(ostream& os, int x){
    os << setw(12) << x; return os;
}

void add(int x, int y, int v, int c){
    //cerr,x,y,v,c;cerr<<endl;
    e[++tot] = (edge){x, y, head[x], v, c}; head[x] = tot;
    e[++tot] = (edge){y, x, head[y], 0, -c}; head[y] = tot;
}

bool spfa(){
    memset(d, 0x7f, sizeof(d));
    //for (int i=s;i<=t;i++){v[i]=0;d[i]=inf;}
    q.push(s); d[s] = 0; v[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop(); v[x] = 0;
        for (int i = head[x], y; i; i = e[i].next)
            if (e[i].v && d[x] + e[i].c < d[y = e[i].go]) {
                d[y] = d[x] + e[i].c; from[y] = i;
                if (!v[y]) {
                    v[y] = 1; q.push(y);
                }
            }
    }
    return d[t] != inf;
}

void mcf(){
    mincost = 0;
    while (spfa()) {
        int tmp = inf;
        for (int i = from[t]; i; i = from[e[i].from]) tmp = min(tmp, e[i].v);
        mincost += d[t] * tmp;maxflow += tmp;
        for (int i = from[t]; i; i = from[e[i].from]) {
            e[i].v -= tmp; e[i ^ 1].v += tmp;
        }
    }
}

int n, m, he[502][502], ttp = 1, nu[502][502];
int main(){
    //ios::sync_with_stdio(0);
    s = 0; t = 1;
    //cin>>n>>m;
    memset(he,0x7f,sizeof(he));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            nu[i][j] = ++ttp;
            scanf("%d", &he[i][j]);//cin >> he[i][j];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if(he[i-1][j]<he[i][j]){add(nu[i][j],nu[i-1][j],INF,0);}
            if(he[i][j-1]<he[i][j]){add(nu[i][j],nu[i][j-1],INF,0);}
            if(he[i+1][j]<he[i][j]){add(nu[i][j],nu[i+1][j],INF,0);}
            if(he[i][j+1]<he[i][j]){add(nu[i][j],nu[i][j+1],INF,0);}
        }
    for(int i=1;i<=m;i++)add(s,nu[1][i],INF,1);

}