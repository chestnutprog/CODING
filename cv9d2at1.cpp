#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int n,t;
int main()
{
	freopen("output2.txt","r",stdin);
	for(int i=1;i<=1000010;i++){
		scanf("%d",&n);
		printf("%d,",t=t^n);
	}
}
