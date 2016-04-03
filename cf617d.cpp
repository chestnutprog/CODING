#include<cstdio>
int x1,y1,x2,y2,x3,y3;
int main(){
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	if(x1==x2&&x2==x3){printf("1");return 0;}
	if(y1==y2&&y2==y3){printf("1");return 0;}
	if(x1==x2){
		if(y2==y3){printf("2");return 0;}
		if(y1==y3){printf("2");return 0;}
	}
	if(x2==x3){
		if(y1==y2){printf("2");return 0;}
		if(y1==y3){printf("2");return 0;}
	}
	if(x1==x3){
		if(y1==y2){printf("2");return 0;}
		if(y2==y3){printf("2");return 0;}
	}
	printf("3");
}
