#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream> 
using namespace std;
int c[5010],h,v[5010],F[5010],n;
int main(){
	scanf("%d%d",&h,&n);
	for(int i=1;i<=h;i++)scanf("%d%d",&v[i],&c[i]);
	for(int i=1;i<=h;i++){
	for(int j=0;j<=n-v[i];j++)
		F[j+v[i]] = max(F[j+v[i]], F[j]+c[i]);
		for(int p=1;p<=n;p++)cout<<F[p]<<' ';
		cout<<endl;
		} 
	printf("%d",F[n]);
}
