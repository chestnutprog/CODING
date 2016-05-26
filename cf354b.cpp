#include <cstdio>
#include <algorithm>
#include<set>
#include<cmath>
using namespace std;
int n,t;
int ans;
long double tower[13][13];
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    scanf("%d%d",&n,&t);
    F1(i,t){
        tower[1][1]+=1.0;
        bool x=1;
        F1(j,n+1)
          F1(k,j)
            if(tower[j][k]>1){
              tower[j+1][k]+=(tower[j][k]-1)/2;
              tower[j+1][k+1]+=(tower[j][k]-1)/2;
              tower[j][k]=1;
            }
    }
    F1(j,n)
      F1(k,j)
    if(tower[j][k]==1)ans++;
      printf("%d",ans);
}
