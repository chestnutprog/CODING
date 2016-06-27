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
template<class T>
struct heap {
    int num; T node[10000010];
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

    void push(T x){
        node[++num] = x; pushup(num);
    }

    inline T top(){
        return node[1];
    }
};
heap<int> q;
int k,n;int a[110];
int main() {
    scanf("%d%d",&k,&n);
    F0(i,k)scanf("%d",&a[i]);
    q.push(1);
    F1(i,n){
        int t=q.top();
        while(q.num>0&&q.top()==t)q.pop();
        F0(i,k)if(a[i]*(long long)t<0x7fffffff&&a[i]*(long long)t>0)q.push(a[i]*t);
    }
    printf("%d",q.top());
}
