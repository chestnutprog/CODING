#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int p[1000100],T,n;
int main()
{
	for(int i=1;i<=1000010;i++)
		for(int j=i;j<=1000010;j+=i)
			p[j]++;
	for(int i=1;i<=1000010;i++)p[i]=p[i-1]^p[i];
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",p[n]);
	}
	return 0;
}
