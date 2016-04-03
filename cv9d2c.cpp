#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("output.txt","w",stdout);
    int n=0,p=0,ans=0;
    while(n++<1000010){
	    int sum=0;
    	for(int i=1;i<=n;i++)sum+=n/i;
    	ans=ans^(sum-p);
    	printf("%d,",ans);
    	p=sum;
    }
}
