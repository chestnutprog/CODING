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
#define mid ((l + r) >> 1)
using namespace std;
int n;
pa a[200010]; int N, M, x, y, c, t, t1, t2;
struct x_xx {
    int l, r; pa val;
} q;
struct node {
    node *ls, *rs;
    pa val;
    inline void pushup(){
        val = max(ls->val, rs->val);
    }

    inline void build(int l, int r){
        if (l == r) {
            val = a[l]; return;
        }
        ls = new node(); rs = new node();
        ls->build(l, mid); rs->build(mid + 1, r);
        pushup();
    }

    inline pa __query_max(int l, int r){
        if (q.l <= l && q.r >= r) return val;
        pa ans = make_pair(0, 0);
        if (q.r > mid) ans = max(ans, rs->__query_max(mid + 1, r));
        if (q.l <= mid) ans = max(ans, ls->__query_max(l, mid));
        return ans;
    }

    inline pa query_max(int l, int r){
        q.l = l, q.r = r;
        return __query_max(1, N);
    }

    inline void __range_add(int l, int r){
        if (q.l <= l && q.r >= r) {
            val = q.val; return;
        }
        if (q.r > mid) rs->__range_add(mid + 1, r);
        if (q.l <= mid) ls->__range_add(l, mid);
        pushup();
    }

    inline void range_add(int l, int c, int d){
        q.l = l, q.r = l; q.val = make_pair(c, d);
        __range_add(1, N);
    }
} Root;
int quw[200005];
int main(){
    ios::sync_with_stdio(0);
    cin >> N;
    for1(i, N) cin >> t1 >> t2, a[t1].second = t1, a[t1].first = t2;
    Root.build(1, N);
    cerr<<"bbuild";
    cin >> M;
    for1(i, M){
        cin >> t;
        for1(j,t){
            cin>>t1;Root.range_add(t1,0,0);quw[j]=t1;
        }
        pa ppp = Root.query_max(1,N);
        cout<<ppp.second<<' '<<ppp.first<<endl;
        for1(j,t){
            Root.range_add(quw[j],quw[j],a[quw[j]].first);
        }
        /*
        if (t == 1) {
            cin >> x >> y >> c;
            Root.range_add(x, y, c);
        } else {
            cin >> x >> y;
            cout << Root.query_sum(x, y) << endl;
        }*/
    }
    return 0;
}

