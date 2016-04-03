#include<cstdio>
int h1,h2,a,b,dis;
int main(){
	scanf("%d%d%d%d",&h1,&h2,&a,&b);
	if(h2-h1>a*8&&b>=a){printf("-1");return 0;}
	for(int i=1;i<=50000;i++){
		dis+=8*a;
		if(h1+dis>=h2){printf("%d",i-1);return 0;}
		dis-=12*b;
		dis+=4*a;
		if(h1+dis>=h2){printf("%d",i);return 0;}
	}
}
	
