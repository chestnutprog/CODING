#include<cstdio>
#include<vector>
#include<map>
#include<iostream>
#include<queue>
using namespace std;
int w1[1000000],w2[1000000],n,m,t,y,l,r;
struct sp{
	int x,c;
};
queue<sp> lazy[1000000];
vector<int> a;
void pushdown(int i){
	while(!lazy[i].empty()){
		sp t=lazy[i].front();
		if(t.x==1){
			w1[i<<1]=max(w1[i<<1],t.c);
			lazy[i<<1].push(t);
			w1[i<<1|1]=max(w1[i<<1|1],t.c);
			lazy[i<<1|1].push(t);
		}else{
			w1[i<<1]+=t.c;
			lazy[i<<1].push(t);
			w1[i<<1|1]+=t.c;
			lazy[i<<1|1].push(t);
		}
		lazy[i].pop();
	}
}
void pushup(int i,int u[]){
	u[i]=min(u[i<<1],u[i<<1|1]);
}
void pushup(int i){
	w1[i]=w2[i]=min(w1[i<<1],w1[i<<1|1]);
}
void maxs(int i,int l1,int r1){
	if(l1<=l&&r1>=r){w1[i]=max(w1[i],y);lazy[i].push((sp){1,y});return;}
	pushdown(i);
	int mid=(l1+r1)>>1;
	if(r<=mid)maxs(i<<1,l1,mid);else
	if(l>mid)maxs(i<<1|1,mid+1,r1);else
	{maxs(i<<1,l1,mid),maxs(i<<1|1,mid+1,r1);}
	pushup(i,w1);
}
void adds(int i,int l1,int r1){
	if(l1<=l&&r1>=r){w1[i]+=y;lazy[i].push((sp){0,y});return;}
	pushdown(i);
	int mid=(l1+r1)>>1;
	if(r<=mid)maxs(i<<1,l1,mid);else
	if(l>mid)maxs(i<<1|1,mid+1,r1);else
	{maxs(i<<1,l1,mid),maxs(i<<1|1,mid+1,r1);}
	pushup(i,w1);
}
void build(int l,int r,int i){
	if(l==r){w1[i]=w2[i]=a[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	pushup(i);
}
void marge(int l,int r,int i){
	if(w1[i]>w2[i])return;
	if(l==r){w2[i]=min(w2[i],w1[i]);return;}
	pushdown(i);
	int mid=(l+r)>>1;
	build(l,mid,i<<1);
	build(mid+1,r,i<<1|1);
	pushup(i,w2);
}
int querya(int i,int l1,int r1){
	if(l1>=l&&r1<=r)return w1[i];
	pushdown(i);
	int mid=(l1+r1)>>1;
	if(r<=mid)return querya(i<<1,l1,mid);else
	if(l>mid)return querya(i<<1|1,mid+1,r1);else
	{return min(querya(i<<1,l1,mid),querya(i<<1|1,mid+1,r1));}
}
int queryb(int i,int l1,int r1){
	if(l1>=l&&r1<=r)return w2[i];
	int mid=(l1+r1)>>1;
	if(r<=mid)return queryb(i<<1,l1,mid);else
	if(l>mid)return queryb(i<<1|1,mid+1,r1);else
	{return min(queryb(i<<1,l1,mid),queryb(i<<1|1,mid+1,r1));}
}
int main(){
	scanf("%d%d",&n,&m);
	a.push_back(0);
	for(int i=1;i<=n;i++)scanf("%d",&t),a.push_back(t);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%d",&t);
		switch(t){
			case 1:
				scanf("%d%d%d",&l,&r,&y);
				adds(1,1,n);
				marge(1,n,1);
				break;
			case 2:
				scanf("%d%d%d",&l,&r,&y);
				adds(1,1,n);
				break;
			case 3:
				scanf("%d%d",&l,&r);
				cout<<querya(1,1,n)<<endl;
				break;
			case 4:
				scanf("%d%d",&l,&r);
				cout<<queryb(1,1,n)<<endl;
				break;
		}
	}
}
