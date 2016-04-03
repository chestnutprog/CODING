#include <cstdio> 
int t[100000],n,sum;
using namespace std;
int main()
{
	scanf("%d%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		t[a]++;t[b]++;
	}
	for(int i=1;i<n;i++)
	if(ans[i]<3)sum++;
	printf("%d",sum);
	for(int i=1;i<=n;++i) 
	if(ans[i]<3)printf("%d ",i);
	return 0;
} 

