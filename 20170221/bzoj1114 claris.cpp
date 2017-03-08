#include<cstdio>
const int N=2010,inf=100000000;
int n,i,j,x,y,z,xl=inf,xr,yl=inf,yr,xm,ym,d,mu,md,l,r;
int f[N][N],h,t,q[N*N][2],ans=inf;
int ul[N],ur[N],dl[N],dr[N],fu[N],fd[N],f11,f1n,fn1,fnn;
char a[N][N],ban[N][N];
inline void umin(int&a,int b){if(a>b)a=b;}
inline void umax(int&a,int b){if(a<b)a=b;}
inline void add(int x,int y,int z){ //z为运动至边界所需的步骤
  if(x<1||x>n||y<1||y>n)return;
  if(ban[x][y]||~f[x][y])return;
  if(x==1)umin(ans,z+xr-xm+1);
  if(x==n)umin(ans,z+xm-xl+1);
  if(y==1)umin(ans,z+yr-ym+1);
  if(y==n)umin(ans,z+ym-yl+1);
  if(x==1&&y==1)umin(ans,z+f11);
  if(x==1&&y==n)umin(ans,z+f1n);
  if(x==n&&y==1)umin(ans,z+fn1);
  if(x==n&&y==n)umin(ans,z+fnn);
  q[++t][0]=x,q[t][1]=y,f[x][y]=z;
}
int main(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)for(scanf("%s",a[i]+1),j=1;j<=n;j++)if(a[i][j]=='r'){
    umin(xl,i);
    umax(xr,i);
    umin(yl,j);
    umax(yr,j);
  }
  for(i=xl;i<=xr;i++){
    for(j=yl;j<=yr;j++)if(a[i][j]!='r')break;
    if(j>yr)xm=i;//xmid
  }
  for(i=yl;i<=yr;i++){
    for(j=xl;j<=xr;j++)if(a[j][i]!='r')break;
    if(j>xr)ym=i;//ymid
  }
  for(i=xl;i<=xm;i++){
    d=xm-i;//the distance from i to xm
    ul[d]=inf;ur[d]=0;
    for(j=yl;j<=yr;j++)if(a[i][j]=='r'){
      umin(ul[d],j);
      umax(ur[d],j);
    }
    ul[d]=ym-ul[d];
    ur[d]=ur[d]-ym;
  }
  for(i=xm;i<=xr;i++){
    d=i-xm;
    dl[d]=inf;dr[d]=0;
    for(j=yl;j<=yr;j++)if(a[i][j]=='r'){
      umin(dl[d],j);
      umax(dr[d],j);
    }
    dl[d]=ym-dl[d];
    dr[d]=dr[d]-ym;
  }
  mu=xm-xl;
  md=xr-xm;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=0;
  for(i=1;i<=n;i++){
    fu[0]=fd[n+1]=inf;
    for(j=1;j<=n;j++)if(a[j][i]=='X')fu[j]=0;else fu[j]=fu[j-1]+1;
    for(j=n;j;j--)if(a[j][i]=='X')fd[j]=0;else fd[j]=fd[j+1]+1;
    for(j=1;j<=n;j++){
      l=n;
      if(fu[j]<=mu)umin(l,i-ur[fu[j]]);
      if(fd[j]<=md)umin(l,i-dr[fd[j]]);
      r=1;
      if(fu[j]<=mu)umax(r,i+ul[fu[j]]);
      if(fd[j]<=md)umax(r,i+dl[fd[j]]);
      umax(l,1),umin(r,n);
      if(l<=r)f[j][l]++,f[j][r+1]--;
    }
  }
  for(i=1;i<=n;i++)for(j=1;j<=n;j++){
    f[i][j]+=f[i][j-1];
    if(f[i][j])ban[i][j]=1;
  }
  f11=f1n=fn1=fnn=inf;
  for(i=1;i<=md;i++){
    umin(f11,i+dr[i]+1);
    umin(f1n,i+dl[i]+1);
    umin(fn1,i+ur[i]+1);
    umin(fnn,i+ul[i]+1);
  }
  for(i=yl;i<=ym;i++){
    d=ym-i;
    ul[d]=inf;ur[d]=0;
    for(j=xl;j<=xr;j++)if(a[j][i]=='r'){
      umin(ul[d],j);
      umax(ur[d],j);
    }
    ul[d]=xm-ul[d];
    ur[d]=ur[d]-xm;
  }
  for(i=ym;i<=yr;i++){
    d=i-ym;
    dl[d]=inf;dr[d]=0;
    for(j=xl;j<=xr;j++)if(a[j][i]=='r'){
      umin(dl[d],j);
      umax(dr[d],j);
    }
    dl[d]=xm-dl[d];
    dr[d]=dr[d]-xm;
  }
  mu=ym-yl;
  md=yr-ym;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=0;
  for(i=1;i<=n;i++){
    fu[0]=fd[n+1]=inf;
    for(j=1;j<=n;j++)if(a[i][j]=='X')fu[j]=0;else fu[j]=fu[j-1]+1;
    for(j=n;j;j--)if(a[i][j]=='X')fd[j]=0;else fd[j]=fd[j+1]+1;
    for(j=1;j<=n;j++){
      l=n;
      if(fu[j]<=mu)umin(l,i-ur[fu[j]]);
      if(fd[j]<=md)umin(l,i-dr[fd[j]]);
      r=1;
      if(fu[j]<=mu)umax(r,i+ul[fu[j]]);
      if(fd[j]<=md)umax(r,i+dl[fd[j]]);
      umax(l,1),umin(r,n);
      if(l<=r)f[l][j]++,f[r+1][j]--;
    }
  }
  for(i=1;i<=n;i++)for(j=1;j<=n;j++){
    f[i][j]+=f[i-1][j];
    if(f[i][j])ban[i][j]=1;
  }
  for(h=i=1;i<=n;i++)for(j=1;j<=n;j++)f[i][j]=-1;
  add(xm,ym,0);
  while(h<=t){
    x=q[h][0],y=q[h++][1],z=f[x][y]+1;
    add(x+1,y,z);
    add(x-1,y,z);
    add(x,y+1,z);
    add(x,y-1,z);
  }
  if(ans<inf)printf("%d",ans);else puts("NIE");
  return 0;
}