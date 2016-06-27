#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int a[31][31];
int f[31][31][60];
int main(){
    int n;
    int a1, a2, a3;
    cin >> n;
    while (cin >> a1 >> a2 >> a3) {
        if (a1 == 0)
            break;
        a[a1][a2] = a3;
    }
    f[1][1][1] = a[1][1];
    for (int i = 2; i < n * 2; i++)
        for (int j = 1; j <= i && j <= n; j++)
            for (int k = 1; k <= i && k <= n; k++) {
                f[j][k][i] = max(f[j][k][i], f[j][k][i - 1]);
                f[j][k][i] = max(f[j][k][i], f[j - 1][k - 1][i - 1]);
                f[j][k][i] = max(f[j][k][i], f[j - 1][k][i - 1]);
                f[j][k][i] = max(f[j][k][i], f[j][k - 1][i - 1]);
                if (j == k)
                    f[j][k][i] = f[j][k][i] + a[j][i - j + 1];
                else
                    f[j][k][i] = f[j][k][i] + a[j][i - j + 1] + a[k][i - k + 1];
            }
    cout << f[n][n][2 * n - 1];
    return 0;
}
