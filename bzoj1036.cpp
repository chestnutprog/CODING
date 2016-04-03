#include<cstdio>
#incldue<cstring>
#define inf 0x7fffffff
#define N 30005
#define M 60005
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for4(i,x) for(int i=head[x];i;i=e[i].next)
using namespace std;
int n,q,tot,sz;
int fa[N][15],v[N],deep[N],size[N],head[N],pos[N],belong[N];
bool vis[N];
struct edge{int go,next;}e[M];
struct seg{int l,r,mx,sum;}t[100005];
void insert(int u,int v){
	e[++tot]=(edge){v,head[u]};head[u]=tot;
	e[++tot]=(edge){u,head[v]};head[v]=tot;
}
void  dfs1(int x){
	size[x]=1;vis[x]=1;
	for1(i,14){if(deep[x]<(1<<i))break;fa[x][i]=fa[fa[x][i-1]][i-1];}
	for4(i,x){
		if(vis[e[i].go])continue;
		deep[e[i].go]=deep[x]+1;
		fa[e[i].go][0]=x;
		dfs1(e[i].go);
		size[x]+=size[e[i].go];
	}
}
void dfs2(int x,int chain){
	int k=0;sz++;
	pos[x]=sz;
	belong[x]=chain;
	for4(i,x)if(deep[e[i].go]>deep[x]&&size[e[i].go]>size[k])k=e[i].go;
