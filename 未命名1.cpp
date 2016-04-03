#include<cstdio>
int a,b,n;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    while(n--){scanf("%d",&b);a+=b;}
    printf("%d",a);
}
