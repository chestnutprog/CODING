#include <cstdio>
#include <algorithm>
using namespace std;
struct o {
    int v, s;
    bool operator <(const o &a) const {
        return v > a.v;
    }
};
o a[2][100010];
int x, y, n, v;
int tot[2];
long long s[2][100010];
int main(){
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1 - 1][tot[t1 - 1]++] = (o){t2, i};
    }
    sort(a[0], a[0] + tot[0]);
    sort(a[1], a[1] + tot[1]);
    //s[0][0] = a[0][0].v;
    //s[1][0] = a[1][0].v;
    for (int i = 1; i <= tot[0]; i++) {
        s[0][i] = s[0][i - 1] + a[0][i - 1].v;
    }
    for (int i = 1; i <= tot[1]; i++) {
        s[1][i] = s[1][i - 1] + a[1][i - 1].v;
    }
    int ans = 0, anst = 0;
    for (int i = 0; i <= tot[1] && 2 * i <= v; i++) {
        if (s[0][ max(min(tot[0], v - 2 * i), 0)] + s[1][i] > anst) {
            ans = i, anst = s[0][ max(min(tot[0], v - 2 * i), 0)] + s[1][i];
        }
    }
    printf("%d ", anst);
    for (int i = 1; i <= ans; i++) {
        printf("%d ", a[1][i - 1].s);
    }
    for (int i = 1; i <= min(tot[0], v - 2 * ans); i++) {
        printf("%d ", a[0][i - 1].s);
    }
}
