#include<cstdio>
#include<cstring>
int fa[100010],edge[100010],ans,n,m;
bool v[100010];
int getfa(int x){
	if(fa[x]<0) return x;
	return fa[x]=getfa(fa[x]);
}
int size(int x){
	return -fa[getfa(x)];
}
void marge(int x,int y)
{
	if(getfa(x)!=getfa(y)){
		fa[getfa(y)]+=fa[getfa(x)];
		edge[getfa(y)]+=edge[getfa(x)];
		fa[getfa(x)]=getfa(y);
	}
	edge[getfa(y)]++;
}
int main(){
	memset(fa,-1,sizeof(fa));
	scanf("%d%d",&n,&m);int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		marge(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!v[getfa(i)]){
			v[getfa(i)]=1;
			if(edge[getfa(i)]==size(i)-1) ans++;
		} 
	}
	printf("%d",ans);
}
