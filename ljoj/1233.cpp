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
template<class T>
struct heap {
    int num; T node[500010]; int i, j;
    inline void pushup(int x){
        j = x, i = j / 2; node[0] = node[j];
        while (j > 0) if (node[i] <= node[0]) {
                break;
            } else {
                node[j] = node[i], j = i, i = i / 2;
            }
        node[j] = node[0];
    }

    inline void pushdown(int x){
        i = 1, j = 2; node[0] = node[i];
        while (j <= x) {
            if (j < x && node[j] > node[j + 1]) {
                j++;
            }
            if (node[0] <= node[j]) {
                break;
            }
            node[i] = node[j];
            i = j; j = i * 2;
        }
        node[i] = node[0];
    }

    inline void pop(){
        node[1] = node[num--]; pushdown(num);
    }

    inline void push(T x){
        node[++num] = x; pushup(num);
    }

    inline T top(){
        return node[1];
    }
};
template<class T>
struct heap2 {
    int num; T node[500010]; int i, j;
    inline void pushup(int x){
        j = x, i = j / 2; node[0] = node[j];
        while (j > 0) if (node[i] >= node[0]) {
                break;
            } else {
                node[j] = node[i], j = i, i = i / 2;
            }
        node[j] = node[0];
    }

    inline void pushdown(int x){
        i = 1, j = 2; node[0] = node[i];
        while (j <= x) {
            if (j < x && node[j] < node[j + 1]) {
                j++;
            }
            if (node[0] >= node[j]) {
                break;
            }
            node[i] = node[j];
            i = j; j = i * 2;
        }
        node[i] = node[0];
    }

    inline void pop(){
        node[1] = node[num--]; pushdown(num);
    }

    inline void push(T x){
        node[++num] = x; pushup(num);
    }

    inline T top(){
        return node[1];
    }
};
heap<int> q; heap2<int> q2;
char s[20];
int n, t;
int main(){
    scanf("%d", &n);
    scanf("%s", s);
    sscanf(s + 4, "%d)", &t);
    q2.push(t); int i = 0;
    F0(j, n - 1){
        scanf("%s", s);
        if (s[0] == 'G') {
            i++;
            printf("%d\n", q2.top());
            if (q.num > 0) {
                q2.push(q.top()), q.pop();
            }
        } else {
            sscanf(s + 4, "%d)", &t);
            if (q2.num <= i) {
                q2.push(t);
            } else if (t >= q2.top()) {
                q.push(t);
            } else {
                q.push(q2.top()), q2.pop(), q2.push(t);
            }
        }
    }
}
