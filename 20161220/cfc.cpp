#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#define inf 1000000000
#define maxn 500 + 100
#define maxm 500 + 100
#define eps 1e-10
#define ll long long
#define pa pair < int, int >
#define for0(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define for2(i, x, y) for (int i = (x); i <= (y); i++)
#define for3(i, x, y) for (int i = (x); i >= (y); i--)
#define mod 1000000007
using namespace std;
int n;
set<int> d, r, dd, dr;
set<int> *dt = &d, *rt = &r;
set<int> *dot = &dd, *ro = &dr;
string x;
int main(){
    cin >> n >> x;
    for0(i, n){
        if (x[i] == 'D') d.insert(i); else r.insert(i);
    }
    do {
        while (dt->size() > 0 && rt->size() > 0) {
            if (*dt->begin() < *rt->begin())
                dot->insert(*dt->begin());
            else
                ro->insert(*rt->begin());
            dt->erase(*dt->begin());
            rt->erase(*rt->begin());
        }

        while (dt->size() > 0) {
            dot->insert(*dt->begin()), dt->erase(*dt->begin()); if (ro->size() > 0) ro->erase(*ro->begin());
        }
        while (rt->size() > 0) {
            ro->insert(*rt->begin()), rt->erase(*rt->begin()); if (dot->size() > 0) dot->erase(*dot->begin());
        }
        swap(dt, dot);
        swap(rt, ro);
    } while (dt->size() > 0 && rt->size() > 0);
    cout << ( (dt->size() > rt->size()) ? 'D' : 'R');
}

