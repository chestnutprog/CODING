#include<cstdio>
long long n,m,a;
int main(){
    scanf("%I64d%I64d%I64d",&n,&m,&a);
    n=n/a+((n%a)>0);
    m=m/a+((m%a)>0);
    printf("%I64d",n*m);
}
