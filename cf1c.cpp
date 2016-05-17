#include <cstdio>
#include <cmath>
const int PI = acos(-1.0);
double x1, y1, x2, y2, x3, y3;
double f[3],a[3][4];
int main(){
    for(int i=1;i<=2;i++)scanf("%lf",&f[i]);
    for(int i=1;i<=2;i++)
      for(int j=1;j<=2;j++)
      {
        double t;
        scanf("%lf",&t);
        a[i][j]=2*(t-f[j]);
        a[i][3]+=t*t-f[j]*f[j];
      }

    printf("%lf", 1);
}
