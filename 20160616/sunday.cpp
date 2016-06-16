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
#define alphabetsize 127
char occ[127];
int m,n;
char p[2000],t[2000];
bool matchesAt(int i){return strstr(t+i,p)-t+i!=-1;}//p[i]==t[i];}
void report(int i){printf("%d ",i);}
void sundayInitocc()
{
    int j;
    char a;
    for (a=0; a<alphabetsize; a++)
        occ[a]=-1;
    for (j=0; j<m; j++)
    {
        a=p[j];
        occ[a]=j;
    }
}
void sundaySearch()
{
    int i=0;
    while (i<=n-m)
    {
        if (matchesAt(i)) report(i);
        i+=m;
        if (i<n) i-=occ[t[i]];
    }
}
int main(){
  scanf("%s%s",t,p);
  n=strlen(t);m=strlen(p);
  sundayInitocc();
  sundaySearch();
}
