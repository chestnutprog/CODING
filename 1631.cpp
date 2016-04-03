#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define inf 10000000
#define maxn 1010
#define maxm 100010
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define for5(i,x) for(int i=head1[x],y=e1[i].go;i;i=e1[i].next,y=e1[i].go)
using namespace std;
int n,m,s;
int d[maxm],d1[maxm];
bool v[maxn],v1[maxn];
int tot,tot1;
int head[maxn],head1[maxn];
queue<int>q;
struct edge{int go,next,w;}e[maxm],e1[maxm];
inline void add(int x,int y,int w)
{
    e[++tot]=(edge){y,head[x],w};head[x]=tot;
    e1[++tot1]=(edge){x,head1[y],w};head1[y]=tot1;
}
int main()
{
	memset(head,0,sizeof(head));
	freopen("sparty.in","r",stdin);
	freopen("sparty.out","w",stdout);
	scanf("%d%d%d",&n,&m,&s);
    for1(i,m){
    	int a,b,c;
    	scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
    for1(i,m)d[i]=inf,d1[i]=inf;
    d[s]=0;q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();v[x]=0;
        for4(i,x)if(d[x]+e[i].w<d[y])
        {
            d[y]=d[x]+e[i].w;
            if(!v[y]){v[y]=1;q.push(y);}
        }
    }
    d1[s]=0;q.push(s);
    while(!q.empty())
    {
        int x=q.front();q.pop();v1[x]=0;
        for5(i,x)if(d1[x]+e1[i].w<d1[y])
        {
            d1[y]=d1[x]+e1[i].w;
            if(!v1[y]){v1[y]=1;q.push(y);}
        }
    }
    int ans=0;
    for1(i,n)ans=max(ans,d[i]+d1[i]);
    cout<<ans<<endl;
    return 0;
}
