#include<cstdio>
using namespace std;
int hh,mm,a,t;
int main(){
	scanf("%d:%d",&hh,&mm);
	scanf("%d",&a);
	t=a+mm;
	mm=t%60;
	hh=(hh+(t/60))%24;
	printf("%02d:%02d",hh,mm);
}