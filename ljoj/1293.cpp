#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define INF 0x7fffffff
long long f[2030][1030];
int cost[2030][2030];
long long s[2030];
int n, i, j, k, l, x;
long long mn = LLONG_MAX;
int main(){
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        s[i] = s[i - 1] + x; cost[i][i + 1] = i;
    }
    for (i = n + 1; i <= 2 * n; i++) {
        s[i] = s[i - n] + s[n]; cost[i][i + 1] = i;
    }
    memset(f, 127 / 3, sizeof(f));
    for (i = 1; i <= 2 * n; i++) {
        f[i][i] = 0, f[i][i + 1] = s[i + 1] - s[i - 1];
    }
    for (l = 1; l <= n; l++) {
        for (i = 1; i <= 2 * n - l; i++) {
            j = i + l;
            for (int k = cost[i][j - 1]; k <= cost[i + 1][j]; k++) {
                if (f[i][j] > f[i][k] + f[k + 1][j] + s[j] - s[i - 1]) {
                    f[i][j] = f[i][k] + f[k + 1][j] + s[j] - s[i - 1];
                    cost[i][j] = k;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        mn = min(mn, f[i][i + n - 1]);
    }
    cout << mn;
    return 0;
}
