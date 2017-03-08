#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40005, MAXM = 5000005;
struct node {
    int to, next, f, c, neg;
} edge[MAXM];
int head[MAXN], top = 0;
void push(int i, int j, int k, int l)
{
    //printf("%d--%d,%d-->%d\n", i, k, l, j);
    ++top, edge[top] = (node) {j, head[i], k, l, top+1}, head[i] = top;
    ++top, edge[top] = (node) {i, head[j], 0, -l, top-1},head[j] = top;
}

int vis[MAXN], dis[MAXN], S = 40001, T = 40002, n, m = 1<<13;
int pre[MAXN], pre_edge[MAXN];
const int inf = 23333333;
queue<int> que;

bool spfa()
{
    memset(vis, 0, sizeof vis);
    memset(pre, 0, sizeof pre);
    memset(dis, 127/3, sizeof dis);
    vis[S] = 1, dis[S] = 0, que.push(S);
    while (!que.empty()) {
        int tp = que.front(); que.pop(); vis[tp] = 0;
        for (int i = head[tp]; i; i = edge[i].next) {
            if (!edge[i].f || dis[edge[i].to] <= dis[tp] + edge[i].c) continue;
            dis[edge[i].to] = dis[tp] + edge[i].c;
            pre[edge[i].to] = tp, pre_edge[edge[i].to] = i;
            if (!vis[edge[i].to]) vis[edge[i].to] = 1, que.push(edge[i].to);
        }
    }
    return dis[T] <= inf;
}

int work(int &cost)
{
    int ans = inf;
    for (int i = T; i != S; i = pre[i]) ans = min(ans, edge[pre_edge[i]].f);
    for (int i = T; i != S; i = pre[i]) edge[pre_edge[i]].f -= ans, edge[edge[pre_edge[i]].neg].f += ans;
    cost += ans*dis[T];
    return ans;
}

int mcf(int &cost)
{
    int ans = 0;
    while (spfa()) ans += work(cost);
    return ans;
}

int main()
{
    for (int i = m; i <= m+m-1; i++) push(i, T, 1, 0);
    for (int i = m-1; i >= 1; i--) push(i, i*2, inf, 0), push(i, i*2+1, inf, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int a, b, c; scanf("%d%d%d", &a, &b, &c); b--;
        for (a += m-1, b += m-1; a < b; a >>= 1, b >>= 1) {
            //cout << a << " " << b << endl;
            if (a&1) push(m+m+i, a++, inf, 0);
            if (!(b&1)) push(m+m+i, b--, inf, 0);
        }
        if (a == b) push(m+m+i, a, inf, 0);
        push(S, m+m+i, 1, -c);
    }
    int cost = 0; mcf(cost);
    cout << -cost << endl;
    return 0;
}