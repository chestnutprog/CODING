#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
long long dis[1010], a[1010], n, s, w[1010];
long long f[1010][1010][2], t[1010][1010];
int main(){
    cin >> n >> s;
    F(i, 1, n) cin >> a[i] >> w[i];
    F(i, 1, n) F(j, i, n) t[i][j] = t[i][j - 1] + w[j];
    int sum = t[1][n];
    F(i, 1, n) F(j, i, n) t[i][j] = sum - t[i][j];
    memset(f, 1, sizeof f);
    f[s][s][0] = f[s][s][1] = 0;
    F(l, 2, n) F(i, 1, n - l + 1){
        int j = i + l - 1;
        f[i][j][0] = min(f[i + 1][j][0] + t[i + 1][j] * (a[i + 1] - a[i]),
                         f[i + 1][j][1] + t[i + 1][j] * (a[j] - a[i]));
        f[i][j][1] = min(f[i][j - 1][1] + t[i][j - 1] * (a[j] - a[j - 1]),
                         f[i][j - 1][0] + t[i][j - 1] * (a[j] - a[i]));
    }
    cout << min(f[1][n][0], f[1][n][1]);
}
