#pragma GCC optimize ("O2")
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
#define INF 0x7fffffff
int dp[30010],ans;
//pair<int,int > p[30010];
int n;
struct ss{
	int s,e,c;
	bool operator<(ss b)const{return s<b.s;}
}p[30010];
int main(){
    scanf("%d",&n);
    F1(i,n)scanf("%d%d%d",&p[i].s,&p[i].e,&p[i].c);//,s.insert(p[i].second),s.insert(p[i].first);
    sort(p+1,p+n+1);
    for(int i=n;i>=1;i--){
      dp[i]=p[i].c;
      for(int j=i+1;j<=n;j++)
        if(p[i].e<=p[j].s)dp[i]=max(dp[i],p[i].c+dp[j]);
      ans=max(ans,dp[i]);
    }
    printf("%d",ans);
}
