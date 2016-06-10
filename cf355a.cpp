#include <cstdio>
#include <algorithm>
#include<set>
#include<cmath>
using namespace std;
int n,h;
int ans;
int t;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    scanf("%d%d",&n,&h);
    F1(i,n){scanf("%d",&t);ans+=1+(t>h);}
    printf("%d",ans);

}
