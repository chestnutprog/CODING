#include<cstdio>
#include<queue>
using namespace std;
#define maxn 200+1
#define maxm 200+1
#define inf 0x7ffffff
int  n,m,s,t,maxflow,tot=1,head[maxn],cur[maxn],h[maxn];
queue<int>q;
struct edge{int go,next,v;}e[maxm];
void add(int x,int y,int v)
{
	e[++tot]=(edge){y,head[x],v};head[x]=tot;
	//e[++tot]=(edge){x,head[y],0};head[y]=tot;
}
bool bfs()
{
    for(int i=s;i<=t;i++)h[i]=-1;
    q.push(s);h[s]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].next)
         if(e[i].v&&h[e[i].go]==-1)
         {
            h[e[i].go]=h[x]+1;q.push(e[i].go);
         }
    }
    return h[t]!=-1;
}
int dfs(int x,int f)
{
    if(x==t) return f;
    int tmp,used=0;
    for(int i=cur[x];i;i=e[i].next)
     if(e[i].v&&h[e[i].go]==h[x]+1)
    {
        tmp=dfs(e[i].go,min(e[i].v,f-used));
        e[i].v-=tmp;if(e[i].v)cur[x]=i;
        e[i^1].v+=tmp;used+=tmp;
        if(used==f)return f;       
    }
    if(!used) h[x]=-1;
    return used;
}
void dinic()
{
    maxflow=0;
    while(bfs())
    {
        for (int i=s;i<=t;i++)cur[i]=head[i];
        maxflow+=dfs(s,inf);
    }
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){int x,y,v;scanf("%d%d%d",&x,&y,&v);add(x,y,v);}
	s=1;t=m;
	dinic();
	printf("%d",maxflow);

}
