#include<cstdio>
long long a,b,c;
int main(){
  printf("%d",-1000%-100);
    scanf("%I64d%I64d%I64d",&a,&b,&c);

    if(c==0){printf("%s",(a==b)?"YES":"NO");return 0;}
    printf("%s",((b-a)/c)>=0&&((b-a)/c)*c==b-a?"YES":"NO");
}
