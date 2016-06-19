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
int a[100010];
int n, ans;
int main(){
    scanf("%d", &n);
    F1(i, n) scanf("%d", &a[i]);
    sort(a +1, a + n +1);
    F1(i, n){
        if (a[i] < ans) {
            continue;
        } else {
            a[i] = a[i - 1] + 1;
            ans = max(ans, a[i] + 1);
        }
    }
    printf("%d", ans);
}
