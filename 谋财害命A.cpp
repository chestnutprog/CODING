#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int n, has[100010];
string s;
int inv[10000];
int main(){
    inv[0] = inv[1] = 1;
    has[0] = 1;
    ios::sync_with_stdio(0);
    for (int i = 2; i <= 9973; i++) {
        inv[i] = ((9973 / i + 1) * inv[i - 9973 % i]) % 9973;
    }
    while (cin >> n) {
        cin >> s;
        for (int j = 1; j <= s.length(); j++) {
            has[j] = (has[j - 1] * (s[j - 1] - 28)) % 9973;
        }
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            cout << (has[r] * inv[has[l - 1]]) % 9973 << endl;
        }
    }
}
