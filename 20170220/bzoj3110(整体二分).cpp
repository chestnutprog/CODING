#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
#define mid ((l+r)>>1)
int n,m;
int tot,ans[N];
ll c[2][N];
bool bo[N];
struct node{
    int k,x,y,z,id;
}a[N],b[N];
inline void ins(int k,int x,int t){
    for(;x<=tot;x+=x&-x)c[k][x]+=t;
}
inline ll getsum(int k,int x){
    ll t=0;for(;x;x-=x&-x)t+=c[k][x];return t;
}
void mdy(int x,int y,int z){
    ins(0,x,z);ins(1,x,z*(x-1));ins(0,y+1,-z);ins(1,y+1,-z*y);
}
ll qry(int x,int y){
    return getsum(0,y)*y-getsum(1,y)-getsum(0,x-1)*(x-1)+getsum(1,x-1);
}
void solve(int x,int y,int l,int r){
    int i,j=x,k=x;
    if(l==r){
        for(i=x;i<=y;i++)if(a[i].k)ans[a[i].id]=l;
        return ;
    }
    for(i=x;i<=y;i++)
        if(a[i].k){
            ll tmp=qry(a[i].x,a[i].y);
            if(tmp < a[i].z){bo[i]=0;a[i].z-=(int)tmp;}
            else{bo[i]=1;k++;}
        }else if(a[i].z<=mid){
            mdy(a[i].x,a[i].y,1);bo[i]=1;k++;
        }else bo[i]=0;
    for(i=x;i<=y;i++)
        if(!a[i].k&&a[i].z<=mid)mdy(a[i].x,a[i].y,-1);
    for(i=x;i<=y;i++)
        if(bo[i])b[j++]=a[i];else b[k++]=a[i];
    for(i=x;i<=y;i++)a[i]=b[i];
    solve(x,j-1,l,mid);solve(j,y,mid+1,r);
}
int main(){
    
}