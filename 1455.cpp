#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
struct p {
    int w, n;
    p(int a, int b){
        w = a, n = b;
    }

    bool operator <(const p a) const {
        return w > a.w;
    }
};
__gnu_pbds::priority_queue<p> a[1000000];
bool d[1000000];
int n, m, fa[1000000];
inline int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        a[i].push(p(t, i));
        fa[i] = i;
    }
    d[0] = 1;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        char t = '\0'; int b, c;
        while (t != 'M' && t != 'K') t = getchar();
        scanf("%d", &b);
        if (t == 'M') {
            scanf("%d", &c);
            if (d[b] || d[c]) {
                continue;
            }
            if (getfa(b) == getfa(c)) {
                continue;
            }
            a[getfa(b)].join(a[getfa(c)]);
            fa[getfa(c)] = getfa(b);
        } else {
            if (!d[b]) {
                d[a[getfa(b)].top().n] = 1;
                printf("%d\n", a[getfa(b)].top().w);
                a[getfa(b)].pop();
            } else {
                printf("0\n");
            }
        }
    }
}
