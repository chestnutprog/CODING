#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
struct cmp {
    inline bool operator() (const int &a,const int &b) const{
        return a <= b;
    }
};
tree<int, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update> T;
int n;
pair<int, int> car[300010];
long long ans;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> car[i].first >> car[i].second;
    sort(car + 1, car + n + 1);
    for (int i = n; i >= 1; i--) {
        //cerr<<car[i].second<<' ';
        ans += T.order_of_key(car[i].second);
        T.insert(car[i].second);
    }
    printf("%lld", ans);
}