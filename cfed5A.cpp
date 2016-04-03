#include<cstdio>
#include<cstring>
char x[1000010],y[1000010],*a,*b;
int tota,totb;
int main(){
	a=x,b=y;
	scanf("%s\n%s",x,y);
	while(x[tota++]=='0')a++;
	while(y[totb++]=='0')b++;
	tota=strlen(a);
	totb=strlen(b);
	if(tota!=totb){
		if(tota>totb)printf(">");else printf("<");
	}else{
		int tot=0;
		switch(strcmp(a,b)){
			case -1:
				printf("<");
				break;
			case 0:
				printf("=");
				break;
			case 1:
				printf(">");
				break;
			}
	}
}
