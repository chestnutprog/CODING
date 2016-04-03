#include<cstdio>
#include<algorithm>
using namespace std;
int bcj[20010],n,m;
struct edge{
	int u,v,w;
}edges[100010];
int getfa(int x){
	return bcj[x]==x?x:bcj[x]=getfa(bcj[x]);
}
int comp(const edge &a,const edge &b){return a.w>b.w;}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edges[i].u ,&edges[i].v,&edges[i].w);
	sort(edges+1,edges+m+1,comp);
	for(int i=1;i<=m;i++)bcj[i]=i;
	for(int i=1;i<=m;i++)
		if(getfa(edges[i].u)!=getfa(edges[i].v)){
			bcj[getfa(edges[i].u)]=getfa(edges[i].v);
		}else{
			printf("%d",edges[i].w);
			return 0;
		}
	printf("0");
}
