#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#define maxn 100010
typedef long long ll;
using namespace std;

ll read(){
    ll x = 0, f = 1; char ch = getchar();
    while (ch > '9' || ch < '0'){ if (ch == '-') f = -1; ch = getchar();}
    while (ch <= '9' && ch >= '0'){ x = x * 10 + ch -'0'; ch = getchar();}
    return x*f;
}
ll n, k, h, t;
ll sum = 0, ans = 10000000000000;
ll q[maxn], a[maxn], f[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

    n = read(); k = read();
    for (int i = 1; i <= n; i++){
        a[i] = read(); sum += a[i];
    }
    f[0] = 0;
    h = t = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++){
        while (i - k - 1 > q[h]) h++;
        f[i] = f[q[h]] + a[i];
        while (f[q[t]] >= f[i]) t--;
        q[++t] = i;
        if (i + k >= n) ans = min(ans, f[i]);
    }
    printf("%lld", sum - ans);

    return 0;
}

