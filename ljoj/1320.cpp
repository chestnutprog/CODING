#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int a[101][101], pd[101][101] = {0}, m, f = 0;
int x, y;
void search(int i, int j, int s){
    if (pd[i][j] > s || i<1 || j<1 || i>x || j>y)
        return;
     else
        pd[i][j] = s;
    if (s > m)
        m = s;
    if (a[i][j + 1] < a[i][j])
        search(i, j + 1, s + 1);
    if (a[i + 1][j] < a[i][j])
        search(i + 1, j, s + 1);
    if (a[i][j - 1] < a[i][j])
        search(i, j - 1, s + 1);
    if (a[i - 1][j] < a[i][j])
        search(i - 1, j, s + 1);
}

int main(){
    cin >> x >> y;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            cin >> a[i][j];
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (pd[i][j] == 0) {
                m = 0;
                search(i, j, 0);
                if (f < m)
                    f = m;
            }
    cout << f + 1;
    return 0;
}
