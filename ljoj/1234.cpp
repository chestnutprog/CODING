#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <sstream>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
struct Ite {
    int s, b;
    Ite(int s, int b) : s(s), b(b) {
    }
    Ite(){}
    bool operator <(const Ite& rhs) const {
        return s < rhs.s;
    }
    bool operator >(const Ite& rhs) const {
        return s > rhs.s;
    }
    bool operator <=(const Ite& rhs) const {
        return s <= rhs.s;
    }
};
struct heap {
    int num; Ite node[1000010];
    void pushup(int x){
        int j = x, i = j / 2; node[0] = node[j];
        while (j > 0) if (node[i] <= node[0]) {
                break;
            } else {
                node[j] = node[i], j = i, i = i / 2;
            }
        node[j] = node[0];
    }

    void pushdown(int x){
        int i = 1, j = 2; node[0] = node[i];
        while (j <= x) {
            if (j < x && node[j] > node[j + 1]) {
                j++;
            }
            if (node[0] <= node[j]) {
                break;
            }
            node[i] = node[j]; i = j; j = i * 2;
        }
        node[i] = node[0];
    }

    void pop(){
        node[1] = node[num--]; pushdown(num);
    }

    void push(Ite x){
        node[++num] = x; pushup(num);
    }

    inline Ite top(){
        return node[1];
    }
} q;
int tot1, tot2; int ans; int t, n; string x; bool tp;
int a[100010], b[100010], c[100010];
int main(){
    getline(cin, x);
    istringstream is(x);
    while (is >> t) a[tot1++] = t;
    sort(a, a + tot1);
    getline(cin, x);
    istringstream bs(x);
    while (bs >> t) b[tot2++] = t;
    sort(b, b + tot2);n=tot2;
    F0(i,n) {
        q.push(Ite(a[i] + b[0], 0));
    }
    F0(i,n) {
        Ite item = q.top(); q.pop();
        c[i] = item.s;
        int bb = item.b;
        if (bb + 1 < n) {
            q.push(Ite(item.s - b[bb] + b[bb + 1], bb + 1));
        }
    }
    F0(i,n-1)printf("%d ",c[i]);printf("%d",c[n-1]);
}
