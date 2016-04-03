#include<cstdio>
#include<cmath>
double x1,yy1,x2,y2,x3,y3;
int main(){
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&yy1,&x2,&y2,&x3,&y3);
	double a=sqrt((x1-x2)*(x1-x2)+(yy1-y2)*(yy1-y2));
	double b=sqrt((x1-x3)*(x1-x3)+(yy1-y3)*(yy1-y3));
	double c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	double p=(a+b+c)/2;
	printf("%lf",sqrt(p*(p-a)*(p-b)*(p-c)));
}
