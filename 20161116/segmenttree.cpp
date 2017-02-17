#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define mid ((l + r) >> 1)
using namespace std;
int a[200010], N, M, x, y, c, t;
struct x_xx {
    long long l, r, val;
} q;
struct node {
    node *ls, *rs;
    long long val, lazy;
    inline void pushup(){
        val = ls->val + rs->val;
    }

    inline void pushdown(int m){
        if (lazy) {
            ls->val += lazy * (m - (m >> 1));
            rs->val += lazy * (m >> 1);
            ls->lazy += lazy;
            rs->lazy += lazy;
            lazy = 0;
        }
    }

    inline void build(int l, int r){
        if (l == r) {
            val = a[l]; return;
        }
        ls = new node(); rs = new node();
        ls->build(l, mid); rs->build(mid + 1, r);
        pushup();
    }

    inline long long __query_sum(int l, int r){
        if (q.l <= l && q.r >= r) return val;
        pushdown(r - l + 1);
        long long ans = 0;
        if (q.r > mid) ans += rs->__query_sum(mid + 1, r);
        if (q.l <= mid) ans += ls->__query_sum(l, mid);
        return ans;
    }

    inline long long query_sum(int l, int r){
        q.l = l, q.r = r;
        return __query_sum(1, N);
    }

    inline void __range_add(int l, int r){
        if (q.l <= l && q.r >= r) {
            val += q.val * (r - l + 1); lazy += q.val; return;
        }
        pushdown(r - l + 1);
        if (q.r > mid) rs->__range_add(mid + 1, r);
        if (q.l <= mid) ls->__range_add(l, mid);
        pushup();
    }

    inline void range_add(int l, int r, int c){
        q.l = l, q.r = r; q.val = c;
        __range_add(1, N);
    }
} Root;
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    for1(i, N) cin >> a[i];
    Root.build(1,N);
    cin >> M;
    for1(i, M){
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> c;
            Root.range_add(x, y, c);
        } else {
            cin >> x >> y;
            cout << Root.query_sum(x, y) << endl;
        }
    }
    return 0;
}