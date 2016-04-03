#include<cstdio>
#include<cmath>
int p(int x){
    int a = sqrt(x);
    for(int i=2;i<=a;i++)if(x%i==0)return 0;
    return 1;
}
int n;
int main(){
	freopen("ÖÊÊý±í","w",stdout); 
    scanf("%d",&n);
    for(int i=2;i<n;i++)if(p(i))printf("%d,",i);
}
