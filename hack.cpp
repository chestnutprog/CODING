#include<cstdio>
#include<cmath>
double x;
int main(){
scanf("%lf",&x);
if(x<=10){
printf("2.5");
}else{
printf("%.1lf",((int)x-10)*1.5+2.5); 
}
}
