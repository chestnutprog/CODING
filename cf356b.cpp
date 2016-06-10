#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int n,a;
int c[110];
int t,p;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    scanf("%d%d",&n,&a);
    F1(i,n)scanf("%d",&c[i]);
    F0(i,min(a,n-a+1)){
        if(c[a+i]!=c[a-i])t++;
    }
    F1(i,n)p+=c[i];
    printf("%d",p-t);
}
