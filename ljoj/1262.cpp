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
char s[500010]; char w[21][25];
bool ss[21][500010];
int b[25];
int n; int len;int lens[21];
int dp[500010];
void kmpPreprocess(int x)
{
	char *p=w[x]+1;
	memset(b,0,sizeof(b));
    int i=0, j=-1;int m = strlen(p);b[i]=j;
    w[x][i]=j;
    while (i<m)
    {
        while (j>=0 && p[i]!=p[j]) j=b[j];
        i++; j++;
        b[i]=j;
    }
}
void kmpSearch(int x)
{
	int n= len;char *p=w[x]+1;
    int i=0, j=0;int m = strlen(p);
    while (i<n)
    {
        while (j>=0 && s[i]!=p[j]) 
		j=b[j];
        i++; j++;
        if (j==m)
        {
            //report(i-j);
            ss[x][i-j]=1;
            j=b[j];
        }
    }
}
int main(){
    scanf("%s%d", s , &n); len = strlen(s);
    F0(i, n){
        scanf("%s", w[i]+1);lens[i]=strlen(w[i]+1);kmpPreprocess(i);kmpSearch(i);
        
    }
	for(int j=0;j<=len;j++)
    F0(i,n)  
      if(j>=lens[i]-1&&ss[i][j-lens[i]+1])dp[j] = max(dp[j],dp[j-lens[i]]+lens[i]);//else dp[j]=max(dp[j],dp[j-1]);
      int ans=0;
    F0(i,len){ans=max(ans,dp[i]);}
    printf("%d",ans);
}
