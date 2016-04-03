#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int c,h,v[5010],F[5010];
int main(){
	scanf("%d%d",&c,&h);
	for(int i=1;i<=h;i++)scanf("%d",&v[i]);
	for(int i=1;i<=h;i++)
	for(int j=c-v[i];j>=0;j--)
		F[j+v[i]] = max(F[j+v[i]], F[j]+v[i]);
	printf("%d",F[c]);
}
