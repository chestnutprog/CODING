#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define MAXN 800005
int n,m,sz;
int root[MAXN],ls[MAXN*10],rs[MAXN*10],fa[MAXN*10],deep[MAXN*10];
void build(int &k,int l,int r){
    if(!k)k=++sz;
    if(l==r){fa[k]=l;return;}
    int mid=(l+r)>>1;
    build(ls[k],l,mid);
    build(rs[k],mid+1,r);
}
void modify(int l,int r,int x,int &y,int pos,int val){
    y=++sz;
    if(l==r){fa[y]=val;return;}
    ls[y]=ls[x];rs[y]=rs[x];
    int mid=(l+r)>>1;
    if(pos<=mid)modify(l,mid,ls[x],ls[y],pos,val);
    else modify(mid+1,r,rs[x],rs[y],pos,val);
}
int query(int k,int l,int r,int pos){
    if(l==r)return k;
    int mid=(l+r)>>1;
    if(pos<=mid)return query(ls[k],l,mid,pos);
    else return query(rs[k],mid+1,r,pos);
}
void add(int k,int l,int r,int pos)
{
	if(l==r){deep[k]++;return;}
	int mid=(l+r)>>1;
	if(pos<=mid)add(ls[k],l,mid,pos);
	else add(rs[k],mid+1,r,pos);
}
int find(int k,int x){
    int p=query(k,1,n,x);
    if(x!=fa[p])return find(k,fa[p]);
    return p;
}
int lastans;
int main(){
    scanf("%d%d",&n,&m);
    build(root[0],1,n);
    int f,k,a,b,p,q;
    F1(i,m){
        scanf("%d",&f);
        switch (f) {
            case 1:
                root[i]=root[i-1];
                scanf("%d%d",&a,&b);
                //a^=lastans;b^=lastans;
                p=find(root[i],a);q=find(root[i],b);
                if(deep[p]>deep[q])swap(p,q);
                modify(1,n,root[i-1],root[i],fa[p],fa[q]);
                if(deep[p]==deep[q])add(root[i],1,n,fa[q]);
                break;
            case 2:
                scanf("%d",&k);
                //k^=lastans;
                root[i]=root[k];
                break;
            case 3:
                root[i]=root[i-1];
                scanf("%d%d",&a,&b);
                //a^=lastans;b^=lastans;
                p=find(root[i],a);q=find(root[i],b);
                if(fa[p]==fa[q])puts("1"),lastans=1;
                else puts("0"),lastans=0;
        }
    }
}
