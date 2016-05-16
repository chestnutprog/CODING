#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 1010 * 1010
#define maxm 6 * 1010 * 1010
#define P(x, y) ((y - 1) * m + x)
#define inf 0x7fffffff
using namespace std;
int n, m, s, t, maxflow, tot = 1, head[maxn], cur[maxn], h[maxn];
queue<int>q;
struct edge {int go, next, v; } e[maxm];
void add(int x, int y, int v){
    e[++tot] = (edge){y, head[x], v}; head[x] = tot;
    e[++tot] = (edge){x, head[y], v}; head[y] = tot;
    //swap(x,y);
    //e[++tot]=(edge){y,head[x],v};head[x]=tot;
    //e[++tot]=(edge){x,head[y],0};head[y]=tot;
}

bool bfs(){
    for (int i = s; i <= t; i++) {
        h[i] = -1;
    }
    q.push(s); h[s] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = e[i].next) {
            if (e[i].v && h[e[i].go] == -1) {
                h[e[i].go] = h[x] + 1; q.push(e[i].go);
            }
        }
    }
    return h[t] != -1;
}

int dfs(int x, int f){
    if (x == t) {
        return f;
    }
    int tmp, used = 0;
    for (int i = cur[x]; i; i = e[i].next) {
        if (e[i].v && h[e[i].go] == h[x] + 1) {
            tmp = dfs(e[i].go, min(e[i].v, f - used));
            e[i].v -= tmp; if (e[i].v) {
                cur[x] = i;
            }
            e[i ^ 1].v += tmp; used += tmp;
            if (used == f) {
                return f;
            }
        }
    }
    if (!used) {
        h[x] = -1;
    }
    return used;
}

void dinic(){
    maxflow = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) {
            cur[i] = head[i];
        }
        maxflow += dfs(s, inf);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int te;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &te);
            add(P(i, j), P(i, j + 1), te);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &te);
            add(P(i, j), P(i + 1, j), te);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            scanf("%d", &te);
            add(P(i, j), P(i + 1, j + 1), te);
        }
    }
    s = P(1, 1), t = P(n, m);
    dinic();
    printf("%d", maxflow);
}
