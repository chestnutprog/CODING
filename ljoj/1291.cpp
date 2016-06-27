#include <cstdio>

static int f[32010]; // f[i] = the max result when i money
static int val[100][10], wgt[100][10];

int main(){
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, p, q; scanf("%d%d%d", &v, &p, &q);
        if (q) {
            q--, val[q][val[q][1] ? 2 : 1] = v, wgt[q][wgt[q][1] ? 2 : 1] = p * v;
        } else {
            val[i][0] = v, wgt[i][0] = v * p;
        }
    }
    for (int i = 0; i < m; i++) {
        if (wgt[i][0]) {
            for (int j = n; j > 0; j--) {
                if (j >= val[i][0] && f[j] < (f[j - val[i][0]] + wgt[i][0])) {
                    f[j] = f[j - val[i][0]] + wgt[i][0];
                }
                if (j >= (val[i][0] + val[i][1]) && f[j] < (f[j - val[i][0] - val[i][1]] + wgt[i][0] + wgt[i][1])) {
                    f[j] = f[j - val[i][0] - val[i][1]] + wgt[i][0] + wgt[i][1];
                }
                if (j >= (val[i][0] + val[i][2]) && f[j] < (f[j - val[i][0] - val[i][2]] + wgt[i][0] + wgt[i][2])) {
                    f[j] = f[j - val[i][0] - val[i][2]] + wgt[i][0] + wgt[i][2];
                }
                if (j >= (val[i][0] + val[i][1] + val[i][2]) &&
                    f[j] < (f[j - val[i][0] - val[i][1] - val[i][2]] + wgt[i][0] + wgt[i][1] + wgt[i][2])) {
                    f[j] = f[j - val[i][0] - val[i][1] - val[i][2]] + wgt[i][0] + wgt[i][1] + wgt[i][2];
                }
            }
        }
    }
    printf("%d\n", f[n]);
    return 0;
}
