#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int node[50001];
int nodea[50001][15][2];
int n,q,t1,t2,tot;
struct edge{
    int go,next;
}e[50010];
int head[50010];
void dfs(int x ,int last){
    F0(i,15){
      if(node[last]&(1<<(i))){ 
          nodea[last][i][1]=1;
          nodea[last][i][0]=0;
      }else{ 
          nodea[last][i][0]=1;
          nodea[last][i][1]=0;
          } 
    }
    for(int i=head[x];i;i=e[i].next){
        dfs(e[i].go,x);
    }
    F0(i,15){
        if((node[last])&(1<<i)){
            nodea[last][i][0]+=nodea[x][i][1];
            nodea[last][i][1]+=nodea[x][i][0];
        }else{
            nodea[last][i][0]+=nodea[x][i][0];
            nodea[last][i][1]+=nodea[x][i][1];
        }
    }
}
int query(int i){
    int ans=0;
    F0(j,15)
      if(node[i]&(1<<j))
      ans+=(1<<j)*nodea[1][j][0];
      else
      ans+=(1<<j)*nodea[1][j][1];
    return ans;
}
int main(){
    scanf("%d%d",&n,&q);
    F1(i,n) scanf("%d",&node[i]);
    F1(i,n-1){
        scanf("%d%d",&t1,&t2);
        e[++tot]=(edge){t2,head[t1]};head[t1]=tot;
    }
    F1(j,q){
        scanf("%d%d",&t1,&t2);
        node[t1]=t2;
        dfs(1,0);
        int tmp=0;
        F1(i,n)tmp+=query(i);
        printf("%d ",tmp);
    }
}
