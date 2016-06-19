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
int n;
int dp[111][4010]; int b[111]; int sum;
int main(){
    scanf("%d", &n);
    F1(i, n) scanf("%d", &b[i]), sum += b[i];
    //sum /= 2;
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    F1(i,n){
        F0(j,sum){
            if (dp[i][j] != -1) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + b[i]);
                if (b[i] >= j) {
                    dp[i + 1][b[i] - j] = max(dp[i + 1][b[i] - j], dp[i][j] - j + b[i]);
                } else {
                    dp[i + 1][j - b[i]] = max(dp[i + 1][j - b[i]], dp[i][j]);
                }
            }
        }
    }
    if (dp[n + 1][0]) {
        printf("%d\n", dp[n + 1][0]);
    } else {
        printf("Impossible\n");
    }
    //  system("pause");
    return 0;
}
