#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int n,x=0,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		q.push(m);
	}
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{ 
		int b,c;
		b=q.top();q.pop();
		c=q.top();q.pop();
		q.push(b+c);
		printf("%d ",b);
		printf("%d ",c);
		printf("%d\n",ans);
		ans+=b+c;
	}
	printf("%d",ans);
	return 0;
}
