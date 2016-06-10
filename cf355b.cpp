#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int n, h, k;
long long ans;
int now;
int a[100010];
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    scanf("%d%d%d", &n, &h, &k);
    F1(i, n) scanf("%d", &a[i]);
    int i = 1;
    while (i <= n) {
        if (now + a[i] <= h) {
            now += a[i]; i++;
        }
        ans += now / k;
        now = now % k;
        if (now + a[i] > h) {
            now = 0; ans++;
        }
    }
    if (now > 0) {
        ans++;
    }
    printf("%I64d", ans);
}
