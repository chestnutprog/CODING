#include<cstdio>
#include<stack>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int head[100001],next[100001],deep[100001],to[100001],p[100001][1000];
inline void dfs(int u)
{
  int i;
  for(i=head[u];i;i=next[i])  
  {  
    if (!deep[to[i]])
    {			
      deep[to[i]] = deep[u]+1;
      p[to[i]][0] = u; //p[x][0]保存x的父节点为u;
      dfs(to[i]);
    }
  }
}


int main(){
	
	
}
