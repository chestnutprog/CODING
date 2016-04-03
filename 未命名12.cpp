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
void dfs(int yuan,int now,int left,int quan){
	if(yuan==-1) {
		edge hh=tot[now];
		bool sig=0;
		do{
			sig=0;
			dfs(now,hh.v,2,w[now]);
			if(!vi[hh.v]){
				vi[hh.v]=1;
				dfs(-1,hh.v,-1,-1);
			}
			if(hh.next!=NULL){hh=*hh.next;sig=1;};
		}while(sig);
		return ;
	}
	{
		edge hh=tot[now];
		bool sig=0;
		do{
			if(hh.v!=yuan){
				if(left==2){
					dfs(now,hh.v,1,quan);
				}else{
					totalw+=quan*w[now];
					maxw=max(maxw,quan*w[now]);
				}	
			}
			if(hh.next!=NULL){hh=*hh.next;sig=1;};
		}while(sig);
	} 
}
int main()   
{     
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
	} 
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	memset(vi,0,sizeof(vi));
	dfs(-1,1,-1,-1); 
	printf("%d %d",maxw,totalw*2);
    return 0;   
} 
