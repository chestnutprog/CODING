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
inline int table(char x){return x<='Z'?x-'A'+26:x-'a';}
int x[2000010];
char t[2000010];
int nexts[52];
int len;
int m;
int T,s,l,r,ans;
int main(){
    freopen("fantasy.in","r",stdin);
    freopen("fantasy.out","w",stdout);
    scanf("%s",t+1);
    len = strlen(t+1);
    F1(i,len)x[i]=table(t[i]);
    scanf("%d",&T);
    while(T--){
      scanf("%d",&s);
      switch (s) {
        case 1:
        scanf("%s",&t);
        x[1+len++]=(table(t[0])+ans)%52;
        //F0(i,len)printf("%d ",x[i]);printf("\n");
        break;
        case 2:
        x[1+len--]='\0';
        break;
        case 3:
        scanf("%d%d%s",&l,&r,t+1);
        l^=ans;r^=ans;m=strlen(t+1);F1(i,m)t[i]=(table(t[i])+ans)%52;
        int j=0;ans=0;memset(nexts,0,sizeof(nexts));
        F(i,2,m)
        {
         while(j&&t[j+1]!=t[i])j=nexts[j];
         if(t[j+1]==t[i])j++;
         nexts[i]=j;
        }
        j=0;
        F(i,l,r)
        {
         while(j&&t[j+1]!=x[i])j=nexts[j];
         if(t[j+1]==x[i])j++;
         if(j==m)ans++,j=nexts[j];
        }
        printf("%d\n",ans);
      }
    }
}
