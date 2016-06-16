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
#define maxn 20050
#define maxm 20050
#define inf 0x7ffffff
int m,tot=1,head[maxn];
priority_queue<int>q;
struct edge{int from,go,next,v,c;}e[2*maxm];
void add(int x,int y,int v,int c)
{
	e[++tot]=(edge){x,y,head[x],v,c};head[x]=tot;
}
int n,k,c,anss;
int dfs(int x,int w){
    int v=0;
    for (int i=head[x];i;i=e[i].next){
      e[i].v=dfs(e[i].go,e[i].c+w);
      v+=e[i].v;
    }
    if(v==0)q.push(w);
    //anss+=w;
    return v>0?v:1;
}
int main(){
	freopen("mzz.in","r",stdin);
	freopen("mzz.out","w",stdout);
    while(scanf("%d%d%d",&n,&k,&c)!=EOF){
      anss=0;
      memset(head,0,sizeof(head));
      memset(e,0,sizeof(e));
      int u,v,w;
      F1(i,n-1){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,1,w);
        anss += w;
      }
      int p = dfs(0,0);
      int t=0;
      F1(i,k){
      	int u = 0;
      	if(!q.empty())u+=q.top(),q.pop();
      	if(!q.empty())u+=q.top(),q.pop();
      	if(u>c)t+=u-c;
      	else break;
	  }
      printf("%d\n",anss+anss-t);
    }
}
