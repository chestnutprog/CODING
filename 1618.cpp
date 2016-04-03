#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int c,h,v[50100],F[50100],w[50100];
int main(){
	scanf("%d%d",&c,&h);
	for(int i=1;i<=c;i++)scanf("%d%d",&v[i],&w[i]);
	for(int i=1;i<=c;i++)
	for(int j=0;j<=h-v[i];j++)
		F[j+v[i]] = min(F[j+v[i]], F[j]-w[i]);
	printf("%d",F[h]);
}
