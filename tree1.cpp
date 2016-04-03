#include <stdio.h>  
#include <cstring>
#include <cmath>
#include <algorithm> 
int ans[20000],w[200000],n,q,rd[200000];
bool vi[200000];
using namespace std;
struct edge{
	int v;
	edge* next=NULL;
	edge(int a) {v=a; }
	edge(){}
}tot[200000],*end[200000];
struct que{
	int a,b;
	que(int c,int d) {a=c;b=d; }
	que(){}
}qu[20000];
void dfs(int fa,int now){
	edge hh=tot[now];
	bool sig=0,sigg=0;	
		for(int i=1;i<=q;i++)
			if(rd[i]&&(now==qu[i].a||now==qu[i].b))
				ans[i]++;
		for(int i=1;i<=q;i++)
			if(now==qu[i].a||now==qu[i].b) 
				rd[i]|=1;
	do{
		sig=0;

		if(hh.v!=fa){
			dfs(now,hh.v);
		}
		if(hh.next!=NULL){hh=*hh.next;sig=1;};
	}while(sig);
}
int main(){
    scanf("%d%d",&n,&q);    	  
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
	for(int i=1;i<=q;i++) { 	
		int a,b;
		scanf("%d%d",&a,&b);
		qu[i]=que(a,b);
	}
	for(int i=1;i<=n;i++) { 	
		dfs(-1,i);
		memset(rd,0,sizeof(rd));
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}
