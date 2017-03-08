#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn=212644<<1;
LL d[2][maxn], a[100100], M;
void change(int x,LL y){
     LL z=y*x;
     for(int k=x+M;k;k>>=1)d[0][k]+=y,d[1][k]+=z;
}
LL ask(int k,int l,int r){
     LL res=0;
     for (l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1){
         if(~l&1)res+=d[k][l^1];
         if( r&1)res+=d[k][r^1];
     }
     return res;
}
int main(){
    int n,m,i,x,l,r;LL ans; int ch;
    scanf("%d",&n);
    memset(d,0,sizeof(d));
    for(M=1;M<=n;M+=M);
    for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(i=1;i<=n;i++)change(i,a[i]-a[i-1]);
    scanf("%d",&m);
    while (m--){
          scanf("%d",&ch);
          //for(ch=' ';ch!='C'&&ch!='Q';scanf("%c",&ch));
          scanf("%d%d",&l,&r);
          if (ch==2) {
             ans=ask(0,1,r)*(r+1)-ask(1,1,r);
             if(--l)ans-=( ask(0,1,l)*(l+1)-ask(1,1,l) );
             printf("%I64d\n",ans);
          };
          if (ch==1) {
             scanf("%d",&x);
             change(l,x); if(r<n)change(r+1,-x);
          }
    }
}