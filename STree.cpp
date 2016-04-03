#include<cstdio> 
#include<cmath> 
#include<algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define root 1 , n , 1 
#define MAXN 100000
#define tree int l ,int r,int rt
using namespace std;
int SUM[MAXN*4],LAZY[MAXN*4],ll[MAXN*4],rr[MAXN*4];
void putup(int rt)
{
  SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}
void putdown(int rt)
{
  if (LAZY[rt]>0)
  {
  	LAZY[rt<<1] +=LAZY[rt];
	LAZY[rt<<1|1] +=LAZY[rt];
  	if(LAZY[rt]%2){
    SUM[rt<<1] = abs((rr[rt<<1]-ll[rt<<1]+1)-SUM[rt<<1]);
    SUM[rt<<1|1] = abs((rr[rt<<1|1]-ll[rt<<1|1]+1)-SUM[rt<<1|1]);
	}
	LAZY[rt]=0;
  }
}
void build(tree) {
	ll[rt]=l;rr[rt]=r;
	if (l == r)
	{
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	putup(rt);
}
void update(int L,int R,tree)
{
  if (L <= l && r <= R)
  {
    LAZY[rt] ++;
    SUM[rt] = abs((r - l + 1)-SUM[rt]);
    return ;
  }
  putdown(rt);
  int m = (l + r) >> 1;
  if (L <= m) update(L , R  , lson);
  if (m < R) update(L , R , rson);
  putup(rt);
}
int querynum(int L,int R,tree)
{
	if (L <= l && r <= R)
    {
		return SUM[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += querynum(L , R , lson);
	if (R > m)  ret +=  querynum(L , R , rson);
	return ret;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	build(root);
	for(int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==0){
			update(b,c,root);
		}else{
			printf("%d",querynum(b,c,root));
		}
	}
}
	
