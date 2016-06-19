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
#define INF 0x7fffffff
char a[1010], b[1010];
int dp[20][1010][1010][2];
int n, m, k;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", a);
    scanf("%s", b);
    F1(l, k)
    F1(i, n)
    F1(j, m)
    if (a[i - 1] == b[j - 1]) {
        dp[l][i][j][0] = 1 + max(dp[l][i - 1][j - 1][0], dp[l - 1][i - 1][j - 1][1]);
        dp[l][i][j][1] = max(dp[l][i - 1][j - 1][0], dp[l - 1][i - 1][j - 1][1]);
    } else {
        dp[l][i][j][0] = 0;
        dp[l][i][j][1] = max(dp[l][i - 1][j - 1][1], dp[l][i - 1][j - 1][0]);
    }
    printf("%d", max(dp[k][n][m][1], dp[k][n][m][0]));
}
