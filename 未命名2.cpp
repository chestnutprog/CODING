#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
int a,b,op,n=10,t,ans;
int main(){
	while(n--){
		srand(time(0));
		op=rand()%4;
		switch(op){
			case 0:a=rand()%20,b=rand()%20,ans=a+b;printf("%d+%d=",a,b); break;
			case 1:a=rand()%20,b=rand()%20,ans=a-b;printf("%d-%d=",a,b); break;
			case 2:a=rand()%20,b=rand()%(20/a)*a,ans=a*b;printf("%d*%d=",a,b); break;
			case 3:a=rand()%9+1,b=(rand()%((20-a)/a)+1)*a,ans=b/a;printf("%d/%d=",b,a); break;
		}
		scanf("%d",&t);
		printf(t==ans?"Correct\n":"Incorrect\n");
	}
}
