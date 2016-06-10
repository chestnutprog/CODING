#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
int c[]={2,4,3,6,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47},s;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
char p[10];
int main(){
    F0(i,19){
        printf("%d\n",c[i]);
        fflush(stdout);
        scanf("%s",p);
        if(p[0]=='y')s++;
    }
    printf("%s",s>1?"composite":"prime");
}
