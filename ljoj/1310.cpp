#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int c,h,v[50100],F[50100],w[50100];
int main(){
	scanf("%d%d",&c,&h);
	for(int i=1;i<=h;i++)scanf("%d%d",&w[i],&v[i]);
	for(int i=1;i<=h;i++)
	for(int j=0;j<=c-v[i];j++)
		F[j+v[i]] = max(F[j+v[i]], F[j]+w[i]);
	printf("%d",F[c]);
}
