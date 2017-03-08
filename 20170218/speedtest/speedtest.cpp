#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<set>
#define mod 1000000007
#define inf 1000000000
#define maxn 500005
#define maxm 30005*2
#define eps 1e-10
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[maxn];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n=read();
	for1(i,n)a[i]=read();
	for1(i,n)
		for2(j,i,n){
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	for1(i,n)printf("%d\n",a[i]);
	return 0;
}

