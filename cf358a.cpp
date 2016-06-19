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
long long n, m;
long long a[10], b[10];
int main(){
    cin >> n >> m;
    F0(i, 5)
    a[i] = n / 5,
    b[i] = m / 5;
    F1(i, 4)
    a[i] += (n % 5 >= i),
    b[i] += (m % 5 >= i);
    long long ans = a[0] * b[0];
    F1(i, 4)
    ans += a[i] * b[5 - i];
    cout << ans;
}
