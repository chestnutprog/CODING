#include<bits/stdc++.h>
using namespace std;
const int maxn=40005,maxm=40005,INF=INT_MAX;
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
#define FM(i,x) for(int i=head[x];i;i=e[i].next)
struct edge{
    int go,next,flow;
}e[maxm];
int tot=1,head[maxn],h[maxn],s,t,cur[maxn],maxflow;
queue<int> q;
void add(int x,int y,int f){
    e[++tot]=(edge){y,head[x],f},head[x]=tot;
    e[++tot]=(edge){x,head[y],0},head[y]=tot;
}
bool bfs(){
    memset(h,-1,sizeof(h));
    h[s]=0;q.push(s);
    while(!q.empty()){
        int x = q.front();q.pop();
        FM(i,x)
            if(e[i].flow && h[e[i].go]==-1){
                h[e[i].go]=h[x]+1;
                q.push(e[i].go);
            }
    }
    return h[t]!=-1;
}
int dfs(int x,int f){
    if(x==t)return f;
    int tmp,used=0;
    for(int i=cur[x];i;i=e[i].next)
        if(e[i].flow && h[e[i].go]==h[x]+1){
            tmp = dfs(e[i].go,min(e[i].flow,f-used));
            if(e[i].flow -= tmp)cur[x]=i;
            e[i^1].flow+=tmp;
            used+=tmp;
            if(used==f)return f;
        }
    if(!used)h[x]=-1;
    return used;
}
void dinic(){
    maxflow=0;
    while(bfs()){
        memcpy(cur,head,sizeof(cur));
        maxflow+=dfs(s,INF);
    }
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){int x,y,v;scanf("%d%d%d",&x,&y,&v);add(x,y,v);}
	s=1;t=m;
	dinic();
	printf("%d",maxflow);

}