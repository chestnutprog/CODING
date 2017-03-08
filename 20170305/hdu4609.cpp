#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cp;
#define maxn 262145
#define F0(i, n) for (int i = 0; i < (n); i++)
#define F1(i, n) for (int i = 1; i <= (n); i++)
cp a[maxn * 4];
int n, m, L, R[maxn * 4];
const double pi = acos(-1);
void fft(cp a[], int flag){
    F0(i, n) if (i < R[i]) swap(a[i], a[R[i]]);
    for (int i = 1; i < n; i <<= 1) {
        cp wn(cos(pi / i), sin(flag * pi / i)), x, y;
        for (int j = 0; j < n; j += i << 1) {
            cp w(1, 0);
            for (int k = 0; k < i; k++, w *= wn) {
                x = a[j + k];
                y = w * a[j + i + k];
                a[j + k] = x + y;
                a[j + i + k] = x - y;
            }
        }
    }
}

int T, nd;
int d[maxn * 4], e[maxn * 4];
long long sum[maxn * 4];
long long p1, p2;
int main(){
    scanf("%d", &T);
    while (T--) {
        int maxns = 0;
        F0(i, maxn) a[i] = 0; L = 0; p1 = 0;
        scanf("%d", &nd); memset(sum, 0, sizeof sum);
        F0(i, nd) scanf("%d", &d[i]), a[d[i]] += 1, sum[d[i]]++, maxns = max(maxns, d[i]);//F0(i,n+1)cin>>a[i];
        m = maxns * 2 + 1;
        for (n = 1; n <= m; n <<= 1) L++;
        F0(i, n) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
        fft(a, 1);
        F0(i, n) a[i] *= a[i];
        fft(a, -1);
        F0(i, n) e[i] = int(a[i].real() / n + 0.5);
        F0(i, n) e[i << 1] -= sum[i];
        F0(i, n) e[i] >>= 1;
        F0(i, n) sum[i + 1] += sum[i];
        F0(i, n) p1 += e[i] * (sum[n] - sum[i - 1]);
        p2 = nd * (nd - 1ll) * (nd - 2ll) / 6ll;
        printf("%.7f\n", 1 - p1 * 1.0 / p2);
    }
}