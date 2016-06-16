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
#define MAXN 200010
struct s{
  int x,y;
  bool operator<(const s a)const{return a.x==x?a.y>y:a.x<x;}
};
priority_queue<s> q;
int fa[MAXN];
bool point[MAXN];
int size[MAXN];int head[MAXN];set<int> go[MAXN];
int n,k,x,y,tot=-1,t,ans;
queue<pair<int,int>> delaydel;
int getfa(int x){
  return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void add(int x,int y){
  go[x].insert(y);go[y].insert(x);
}
void adds(int t,int y){
	for(set<int>::iterator x = go[t].begin();x!=go[t].end();x++)go[y].insert(*x),delaydel.push(make_pair(t,*x));
}
int main(){
	freopen("deep.in","r",stdin);
  freopen("deep.out","w",stdout);
  scanf("%d%d",&n,&k);
  F1(i,n)fa[i]=i;
  F0(i,n-1){scanf("%d%d",&x,&y);add(x,y);}
  F0(i,k){scanf("%d",&x);point[x]=1;q.push((s){1,x});}
  while(!q.empty()){
    y=getfa(q.top().y);t=q.top().x;q.pop();ans=max(ans,t);
    while(!delaydel.empty())go[delaydel.front().first].erase(delaydel.front().second),delaydel.pop();
    for(set<int>::iterator x = go[y].begin();x!=go[y].end();x++){
      if(!point[getfa(*x)]){fa[*x]=y;adds(*x,y);delaydel.push(make_pair(y,*x));q.push((s){t+1,y});break;}
    }
  }
  printf("%d",ans);
}
