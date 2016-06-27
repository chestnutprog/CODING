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
int p, n, a, b;
double cc, cost;
int f[100010];
int main(){
    while (scanf("%d%d%d%d", &n, &p, &a, &b) != EOF) {
        cc = 0; cost = 0; if (n == 0) {
            return 0;
        }
        F1(i, n){
            if ((1 - ((1 - cc) * (1 - p / 100.0))) * b < a) {
                cost += cc * b;
            } else {
                cc = 0;
                cost += a;
            }
            cc = 1 - ((1 - cc) * (1 - p / 100.0));
        }
        printf("%.4lf\n", cost);
    }
}
