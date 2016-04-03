#include<cstdio> 
#include<cmath> 
#include<algorithm>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define MAXN 100000
#define QN 0
#define QI 1
#define QA 2
#define tree int l ,int r,int rt
using namespace std;
int MAX[MAXN*4],MIN[MAXN*4],SUM[MAXN*4],LAZY[MAXN*4],LIGHT[MAXN*4];
void putup(int rt)
{
  MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
  MIN[rt] = min(MIN[rt<<1] , MIN[rt<<1|1]);
  SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}
void putdown(int rt,int m)
{
  if (LAZY[rt])
  {
    LAZY[rt<<1] += LAZY[rt];
    LAZY[rt<<1|1] += LAZY[rt];
    SUM[rt<<1] += LAZY[rt] * (m - (m >> 1));
    SUM[rt<<1|1] += LAZY[rt] * (m >> 1);
    LAZY[rt] = 0;
  }
}
void build(int l,int r,int rt) {
	if (l == r)
	{
		scanf("%d",&MAX[rt]);
		MIN[rt] = MAX[rt];
		SUM[rt] = MAX[rt];
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	putup(rt);
}
void update(int p,int tihuan,tree)
{
  if (l == r) {
    MAX[rt] = tihuan;
    MIN[rt] = tihuan;
    SUM[rt] = tihuan;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) update(p , tihuan ,lson);
  else update(p , tihuan , rson);
  putup(rt);
}
void update(int L,int R,int c,tree)
{
  if (L <= l && r <= R)
  {
    LAZY[rt] += c;
    SUM[rt] += (long long)c * (r - l + 1);
    return ;
  }
  putdown(rt , r - l + 1);
  int m = (l + r) >> 1;
  if (L <= m) update(L , R , c , lson);
  if (m < R) update(L , R , c , rson);
  putup(rt);
}
void adds(int p,int add,tree)
{
	if (l == r) {
		SUM[rt] = SUM[rt] + add;
		MIN[rt] = SUM[rt];
		MAX[rt] = MIN[rt];
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m) adds(p , add ,lson);
	else adds(p , add , rson);
	putup(rt);
}
int querymax(int L,int R,tree)
{
	if (L <= l && r <= R)
    {
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = -1;
	if (L <= m) ret = max(ret , querymax(L , R , lson));
	if (R > m)  ret =  max(ret , querymax(L , R , rson));
	return ret;
}
int querymin(int L,int R,tree)
{
	if (L <= l && r <= R)
    {
		return MIN[rt];
	}
	int m = (l + r) >> 1;
	int ret = -1>>1;
	if (L <= m) ret = min(ret , querymin(L , R , lson));
	if (R > m)  ret =  min(ret , querymin(L , R , rson));
	return ret;
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

	
