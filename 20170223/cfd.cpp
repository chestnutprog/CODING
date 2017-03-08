#include<bits/stdc++.h>
using namespace std;
bitset<100005> light;
int n,m,tot;
struct edge{
    int go,next;
}e[200002];int head[200002];
inline void add(int x,int y){
    e[++tot]=(edge){y,head[x]};head[x]=tot;
}
int control[100002][2];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){

    }
}
