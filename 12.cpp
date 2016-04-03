#include <stdio.h>  
#include <cstring>
#include <cmath>
#include <algorithm> 
int totalw,maxw,w[200000],n,rd[200000],cd[200000];
bool vi[200000];
using namespace std;
struct edge{
	int v;
	edge* next=NULL;
	edge(int a) {v=a; }
	edge(){}
}tot[200000],*end[200000];
void dfs(int yuan,int now,int left,int quan,int yy){
	if(yuan==-1) {
		edge hh=tot[now];
		bool sig=0;
		do{
			sig=0;
			dfs(now,hh.v,0,w[now],yuan);
			if(hh.next!=NULL) {hh=*hh.next;sig=1;};
		}while(sig);
		return ;
	}
	{
		edge hh=tot[now];
		bool sig=0,sigg=0;
		do{
			sig=0;
			if(hh.v!=yuan&&hh.v!=yy){
					totalw=(totalw+quan*w[hh.v])%10007;
					maxw=max(maxw,quan*w[hh.v]);
			}
			if(hh.next!=NULL){hh=*hh.next;sig=1;};
		}while(sig);
	} 
}
int main()   
{     
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&n);    	  
    for(int i=1;i<n;i++) {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	if(vi[u]){
    		(*end[u]).next = new edge(v);
			end[u]=(*end[u]).next;
		}else{
			vi[u]=1;
			tot[u]=edge(v);
			end[u]=&tot[u];
		}
		if(vi[v]){
    		(*end[v]).next = new edge(u);
			end[v]=(*end[v]).next;
		}else{
			vi[v]=1;
			tot[v]=edge(u);
			end[v]=&tot[v];
		}
	} 
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	memset(vi,0,sizeof(vi));
	for(int i=1;i<=n;i++)dfs(-1,i,-1,-1,-1); 
	printf("%d %d",maxw,totalw%10007);
    return 0;   
} 
