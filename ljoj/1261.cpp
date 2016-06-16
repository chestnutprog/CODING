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
int p[110][110], dp[110][10010], maxs = 0x7ffffff,nu[110];
int n, v;
int main(){
    scanf("%d", &n);
    F0(k, n){
        int i = -1;int len=0; while (i++,1) {
            scanf("%d", &p[k][i]);len+=p[k][i];
			if (p[k][i] == -1) {
                maxs = min(maxs, len+1);nu[k]=i;
				break;
            }
        }
    }
    v=maxs;
    /*F0(pr, n){dp[pr][0]=1;
     F0(i,nu[pr]-1)
      for(int j=p[pr][i];j<=maxs+p[pr][i];j++)
      if(dp[j-p[pr][i]])dp[pr][j]=1;}*/
      F0(pr,n){dp[pr][0]=1;
	  //F0(i,nu[pr])
	  for(int i=nu[pr]-1;i>=0;i--)
      for(int j=v;j>=p[pr][i];j--)
      if(dp[pr][j-p[pr][i]])dp[pr][j]=1;}
    int x = 0; int i;
    for (i = maxs; i >= 0 && !x; i--) {
        x = 1; F0(k, n-1) if (dp[k][i] != dp[k + 1][i]||!dp[k][i]) {
            x &= 0;
        }
    }
    printf("%d", i+1);
}
