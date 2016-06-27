#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int l, s, t, m;
    int a[100000], f[100000], sz[100000];
    memset(sz, 0, sizeof(sz));
    memset(a, 0, sizeof(a));
    memset(f, 127, sizeof(f));
    cin >> l >> s >> t >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    if (s == t) {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (a[i] % s == 0) {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    sort(a, a + m + 1);
    a[m + 1] = l;
    for (int i = 0; i <= m; i++) {
        if (a[i + 1] - a[i] > 90) {
            a[i + 1] = a[i] + (a[i + 1] - a[i]) % 90;
        }
    }
    for (int i = 1; i <= m; i++) {
        sz[a[i]] = 1;
    }
    for (int i = s; i <= t; i++) {
        if (sz[i]) {
            f[i] = 1;
        } else {
            f[i] = 0;
        }
    }
    for (int i = 2 * s; i <= a[m + 1]; i++) {
        for (int j = s; j <= t; j++) {
            if (j > i) {
                break;
            }
            f[i] = min(f[i - j], f[i]);
        }
        if (sz[i]) {
            f[i]++;
        }
    }
    cout << f[a[m + 1]] << endl;
    return 0;
}
