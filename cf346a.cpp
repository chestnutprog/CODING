#include<cstdio>
int main(){
	int a,b,n;
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",(a+b+n*100-1)%n+1);
}
