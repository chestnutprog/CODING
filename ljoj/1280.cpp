#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define inf 1000000000
#define maxn 200000+5
#define maxm 3500000+5
#define eps 1e-10
#define ll long long
#define ull unsigned long long
#define db long double
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define for5(n,m) for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
#define mod 23333333
#define lch k<<1,l,mid
#define rch k<<1|1,mid+1,r
#define sqr(x) (x)*(x)
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,head[maxn],tot,inp[maxn],f[maxn],qqq[maxn];
bool in[maxn],out[maxn];
queue<int>q;
struct edge{int go,next;}e[maxn];
inline void add(int x,int y)
{
if(x>y)swap(x,y);
    e[++tot]=(edge){y,head[x]};head[x]=tot;
}
int main()
{
    n=read();m=read();
    for1(i,n)qqq[i]=read();
    for1(i,m)
    {
        int x=read(),y=read();
        add(x,y);
        inp[y]++;
        out[x]=1;
        in[y]=1;
    }
    for1(i,n)if(!inp[i])q.push(i),f[i]=qqq[i];
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for4(i,x)
        {
            f[y]=max(f[x]+qqq[y],f[y]);
            inp[y]--;
            if(!inp[y])q.push(y);
        }
    }
    int ans=0;
    for1(i,n)ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}
