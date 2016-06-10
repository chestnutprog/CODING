#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int t[6],ans;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    F0(i,5)scanf("%d",&t[i]);
    sort(t,t+5);
    F1(i,4)if(t[i-1]==t[i])ans=max(ans,t[i]*2);
    F1(i,3)if(t[i-1]==t[i]&&t[i]==t[i+1])ans=max(ans,t[i]*3);
    F0(i,5)t[5]+=t[i];
    printf("%d",t[5]-ans);
}
