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
#define paa pair < int, pa >
#define mp make_pair
#define for0(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define for2(i, x, y) for (int i = (x); i <= (y); i++)
#define for3(i, x, y) for (int i = (x); i >= (y); i--)
#define mod 1000000007
using namespace std;
int n, k;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//__gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag,
//                 __gnu_pbds::tree_order_statistics_node_update> T;
__gnu_pbds::tree<pa, __gnu_pbds::null_type, std::less<pa >, __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update> Tf;
//int x[300010], y[300010];
int x, y;
vector<pa > v, vr;
vector<int> ansp;
int main(){
    cin >> n >> k;
    for1(i, n){
        cin >> x >> y;
        v.push_back(mp(x, y));
        vr.push_back(mp(y, x));
    }
    sort(v.begin(), v.end());
    sort(vr.begin(), vr.end());
    vector<pa >::iterator j = vr.begin();
    for (vector<pa >::iterator i = v.begin(); i != v.end(); i++) {
        Tf.insert(*i);
        x = i->first;
        if (Tf.size() >= k) {
            pa l = *Tf.find_by_order(k - 1);
            if (x - l.first + 1 > ans){
                ans = x - l.first + 1;
                ansp.clear();ansp.push_back();
            }

        }


        for (; j->first <= x; j++) Tf.erase(mp(j->second, j->first));
    }
}

