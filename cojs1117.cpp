#include<cstdio>
#include<queue>
#include<cstring>
#define N 1010
#define M 20010
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for4(i,x) for(int i=head[x];i;i=e[i].next)
using namespace std;
int n,ml,md,tot,head[N],dis[N];
bool v[N],flag;
struct edge{int go,next,w;}e[M]; 
void add1(){
	int x,y,w;
	scanf("%d%d%d",&x,&y,&w);
	e[++tot]=(edge){y,head[x],w};head[x]=tot;
}
void add2(){
	int x,y,w;
	scanf("%d%d%d",&x,&y,&w);
	e[++tot]=(edge){x,head[y],-w};head[y]=tot;
}
void spfa(int p){
	if(v[p]){flag=1;return;}
	v[p]=1;
	for4(i,p){
		int w=e[i].w,y=e[i].go;
		if(dis[p]+w<dis[y]){
			dis[y]=dis[p]+w;
			spfa(y);
			if(flag)return;
		}
	}
	v[p]=0;
}
int main(){
	freopen("layout.in","r",stdin);
	freopen("layout.out","w",stdout);
	scanf("%d%d%d",&n,&ml,&md);
	for1(i,ml)add1();
	for1(i,md)add2();
		memset(dis,0x7f,sizeof(dis));
		memset(v,0,sizeof(v));
		dis[1]=0;
		spfa(1);
		if(flag){printf("-1");return 0;}
	if(dis[n]==0x7f7f7f7f)printf("-2");
	else printf("%d",dis[n]);
	
}
