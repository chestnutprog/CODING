#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define MAX 1000010
#define inf 100000000
using namespace std;
int a[MAX];
struct tree{
    int l,r,sum,mx,mi,lazy;
}f[MAX*4];

void pushup(int i){
    f[i].sum=(f[i*2+1].sum+f[i*2].sum);
    f[i].mx=max(f[i*2+1].mx,f[i*2].mx);
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}

void update(int i,int x)
{
    f[i].sum+=x*(f[i].r-f[i].l+1);
    f[i].mi+=x;
    f[i].mx+=x;
    f[i].lazy+=x;
    return;
}

void pushdown(int i){
    if(f[i].lazy!=0){
        update(i*2,f[i].lazy);
        update(i*2+1,f[i].lazy);
        f[i].lazy=0;
        return;
    }
    else return;
}

void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].lazy=0;f[i].mx=0;f[i].mi=inf;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].sum=a[left];
        f[i].mx=a[left];
        f[i].mi=a[left];
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}

void add(int i,int left,int right,int v){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right){
        update(i,v);
        return;
    }
    pushdown(i);
    if(mid>=right)add(i*2,left,right,v);
    else if(mid<left)add(i*2+1,left,right,v);
    else add(i*2,left,mid,v),add(i*2+1,mid+1,right,v);
    pushup(i);
}

int qmin(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    pushdown(i);
    if(mid>=right) return qmin(i*2,left,right);
    if(mid<left) return qmin(i*2+1,left,right);
    return min(qmin(i*2,left,mid),qmin(i*2+1,mid+1,right));
}
inline int read( )
{
    int x=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    x=0;
    while (ch<='9' && ch>='0')
    {
        x*=10,x+=ch-'0';
        ch=getchar();
    }
    return x;
}
int main(){
	freopen("classrooms.in","r",stdin);
	freopen("classrooms.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++) 	a[i]=read();
	build(1,1,n);
	int d,s,t;
	int i=1;
	for(;i<=n;i++)
	{
		d=read();s=read();t=read();
		if(qmin(1,s,t)<d )
			break;
		add(1,s,t,-d);
	}

	if(i<=m)
		cout<<-1<<endl<<i;
	else
		cout<<0;
	return 0;
}

