#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#define DEBUG_
using namespace std;
const int N = 2010, INF = 0x7f7f7f7f;
typedef map<int, map<int, int> >::iterator mppit;
typedef map<int, int>::iterator mpit;
#define maxn 4007
#define maxm 3000005
#define ey e[i].go
#define ef e[i].from
int tot = 1, head[maxn], d[maxn], mincost, s, t, from[maxn];
bitset<maxn> v;
pair<int, int>point[2005];
queue<int> q;
struct edge {
    int from, go, next, flow, cost;
} e[maxm];
ostream& operator ,(ostream &os, int x){
    os << x; return os;
}

ostream& operator ,(ostream &os, string x){
    os << x; return os;
}

ostream& operator ,(ostream &os, char x){
    os << x; return os;
}

void add(int x, int y, int v, int c){
    e[++tot] = (edge){x, y, head[x], v, c}; head[x] = tot;
    e[++tot] = (edge){y, x, head[y], 0, -c}; head[y] = tot;
}

bool spfa(){
    //v.reset();
    memset(d, 0x7f, sizeof(d));
    //for (int i=0;i<=t;i++){d[i]=INF;}
    q.push(s); d[s] = 0; v[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop(); v[x] = 0;
        for (int i = head[x], y; i; i = e[i].next)
            if (e[i].flow && d[x] + e[i].cost < d[y = e[i].go]) {
                d[y] = d[x] + e[i].cost; from[y] = i;
                if (!v[y]) {
                    v[y] = 1; q.push(y);
                }
            }
    }
    return d[t] != INF;
}

void mcf(){
    mincost = 0;
    while (spfa()) {
        int tmp = INF;
        for (int i = from[t]; i; i = from[e[i].from]) tmp = min(tmp, e[i].flow);
        //mincost+=d[t]*tmp;
        for (int i = from[t]; i; i = from[e[i].from]) {
            e[i].flow -= tmp; e[i ^ 1].flow += tmp; mincost += e[i].cost * tmp;
        }
    }
}
#define P1(x) (((x)<<1)-1)
#define P2(x) ((x)<<1)
#define S (n<<1|1)
#define T ((n+1)<<1)
int n,a[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin >> n; t = T; s = S;
    for (int i = 1; i <= n; i++)
        cin >> point[i].first >> point[i].second;
    sort(point+1,point+n+1);
    for (int i = 1; i <= n; i++) {
        a[i] = point[i].second;
        int temp = -1;
        add(0, P1(i), 1, 0);
        add(P2(i), T, 1, 0);
        add(P1(i), P2(i), 1, -1);
        add(P1(i), P2(i), 1, 0);
        for (int j = i - 1; j; j--)
            if (a[j] <= a[i] && a[j] > temp)
                temp = a[j], add(P2(j), P1(i), 2, 0);
        /*
           for(j=1;j<i;j++)
            if(a[j]<=a[i])
                Link(P2(j),P1(i),1,0);
         */
    }
    add(S,0,2,0);
    mcf();
    cout << -mincost;
}