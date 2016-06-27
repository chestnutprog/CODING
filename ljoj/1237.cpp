#pragma GCC optimize ("O4")
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
#include <bitset>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
struct po{
    int x;
    int l;
    po(int x,int l):x(x),l(l){}
    po(){}
    bool operator<(po b)const{return x<b.x;}
    bool operator<=(po b)const{return x<=b.x;}
    bool operator>(po b)const{return x>b.x;}
};
template<typename T>
struct heap {
    int num; T node[6000100];int i,j;
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

};
heap<po> q;
int k,n;int a[110];int mx[110];
int main() {
    scanf("%d%d",&k,&n);
    F1(i,k)scanf("%d",&a[i]);
    sort(a+1,a+k+1);
    q.push(po(a[1],1));
    F1(i,n-1){
        po t=q.node[1];
        while(q.num>0&&q.node[1].x==t.x)
        q.pop();
        if(t.x*(long long)a[t.l]<0x7fffffff)q.push(po(t.x*a[t.l],t.l));
        if(t.x*(long long)a[t.l+1]/a[t.l]<0x7fffffff)if(t.l<k)q.push(po(t.x/a[t.l]*a[t.l+1],t.l+1));
    }
    printf("%d",q.node[1].x);
}
