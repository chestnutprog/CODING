#include<cstdio>
#include<iostream>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,cnt=1,ans,T,S;
int x[2005],y[2005];
int head[4005],q[4005],dis[4005],from[4005];
bool inq[4005],used[2005];
struct data{int to,from,next,v,c;}e[6000005];
void ins(int u,int v,int w,int c)
{
    e[++cnt].to=v;e[cnt].from=u;
    e[cnt].next=head[u];head[u]=cnt;
    e[cnt].v=w;e[cnt].c=c;
}
void insert(int u,int v,int w,int c)
{ins(u,v,w,c);ins(v,u,0,-c);}
bool spfa()
{
    for(int i=0;i<=T;i++)dis[i]=-inf;
    int t=0,w=1;
    dis[0]=0;q[0]=0;inq[0]=1;
    while(t!=w)
    {
        int now=q[t];t++;if(t==4005)t=0;
        for(int i=head[now];i;i=e[i].next)
            if(e[i].v&&e[i].c+dis[now]>dis[e[i].to])
            {
                dis[e[i].to]=e[i].c+dis[now];
                from[e[i].to]=i;
                if(!inq[e[i].to])
                {
                    inq[e[i].to]=1;
                    q[w++]=e[i].to;
                    if(w==4005)w=0;
                }
            }
        inq[now]=0;
    }
    if(dis[T]==-inf)return 0;
    return 1;
}
void dfs()
{
    int x=inf;
    for(int i=from[T];i;i=from[e[i].from])
        x=min(e[i].v,x);
    for(int i=from[T];i;i=from[e[i].from])
        {ans+=x*e[i].c;e[i].v-=x;e[i^1].v+=x;}
}
int main()
{
	//freopen("pacman.in","r",stdin);
	//freopen("pacman.out","w",stdout);
	n=read();T=2*n+2;S=T-1;
	for(int i=1;i<=n;i++)
	    x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++)
	{
	    insert(S,i,1,0);
	    insert(i,i+n,1,1);
	    insert(i+n,T,1,0);
	}
	insert(0,S,2,0);
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        if(x[i]<=x[j]&&y[i]<=y[j]&&i!=j)
	            insert(i+n,j,1,0);
	while(spfa())dfs();
	printf("%d",ans);
	return 0;
}