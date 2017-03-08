#include <bits/stdc++.h>
using namespace std;
#define N 5002
#define maxn N * 10
#define maxm N * 100
#define ey e[i].go
#define INF 0x7f7f7f7f
#define inf INF
bitset<maxn> v;
int d[maxn], from[maxn];
queue<int> q;
int s, t, mincost;
struct edge {
    int from, go, next, v, c;
} e[maxm];
int head[maxn], tot = 1;
ostream& operator,(ostream& os,int x){os<<setw(12)<<x;return os;}
void add(int x,int y,int v,int c)
{
    //cerr,x,y,v,c;cerr<<endl;
	e[++tot]=(edge){x,y,head[x],v,c};head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-c};head[y]=tot;
}
bool spfa()
{
    memset(d,0x7f,sizeof(d));
	//for (int i=s;i<=t;i++){v[i]=0;d[i]=inf;}
	q.push(s);d[s]=0;v[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();v[x]=0;
		for (int i=head[x],y;i;i=e[i].next)
		 if(e[i].v&&d[x]+e[i].c<d[y=e[i].go])
		 {
			d[y]=d[x]+e[i].c;from[y]=i;
			if(!v[y]){v[y]=1;q.push(y);}
		 }
	}
	return d[t]!=inf;
}
void mcf()
{
    mincost=0;
    while(spfa())
	{
		int tmp=inf;
		for(int i=from[t];i;i=from[e[i].from]) tmp=min(tmp,e[i].v);
		mincost+=d[t]*tmp;
		for(int i=from[t];i;i=from[e[i].from]){e[i].v-=tmp;e[i^1].v+=tmp;}
	}
}

#define mid ((l + r) >> 1)
#define tp(x) ((x) + n + 2)
int a[N], b[N], c[N];
int n;
void build(int l, int r, int i){
    if (l == r) {
        add(tp(i), t, 1, 0); return;
    }
    add(tp(i), tp(i << 1), INF, 0);
    add(tp(i), tp((i << 1) | 1 ), INF, 0);
    build(l, mid, i << 1);
    build(mid + 1, r, (i << 1) | 1);
}

int ll, lr, lp;
void link(int l, int r, int i){
    //cerr,l,r,i;cerr<<endl;
    if (ll <= l && lr >= r) {
        add(lp, tp(i), INF, 0);
        return;
    }
    if (lr > mid) link(mid + 1, r, (i << 1) | 1);
    if (ll <= mid) link(l, mid, i << 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n; s = 0 ; t = n + 1;
    build(1, 5001, 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        add(s, i, 1, -c[i]);
        ll = a[i]; lr = b[i] - 1; lp = i;
        link(1, 5001, 1);
    }
    mcf();
    cout << -mincost;
}