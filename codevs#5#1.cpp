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
#define maxn 250000+5
#define maxm 200000+5
#define eps 1e-10
#define ll long long
#define ull unsigned long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
#define for5(n,m) for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
#define mod 1000000007
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
int main()
{
   int n=read();ll ans=0;
   for1(p,n){
   	int t;
   	scanf("%d",&t);
   	int ss=1;
   for(int j=1;j<=t;j++){
		int s=0;
		for(int i=j;i<=t;i++){
			if(i%j==0)s++;
		}
		printf("%d ",ss-s);
		ss=s;
	}
	 printf("\n");
}
  
   return 0;
}
