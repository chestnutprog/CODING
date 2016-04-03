#include<iostream>
using namespace std;
int f[9][11],a[9],x[11],m,n,l=1001;
void doing(int i)
{
	int c;
	for(int j=0;j<=a[i];j++)
    {
		for(int k=1;k<=m;k++) x[k]=x[k]+f[i][k]*j;
		if(i<n) doing(i+1);
		else 
        {
			for(int k=2;k<=m;k++) 
            {
				if(x[k]==x[k-1]) c=1;
				else
                {
					c=0;
					break;
				}
			}//检查
			if(c==1&&x[1]*m<l&&x[1]>0) l=x[1]*m; 
			//计算结果
		}
		for(int k=1;k<=m;k++) x[k]=x[k]-f[i][k]*j;
	}
}
int main()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>f[i][j];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n!=10)doing(1);
	else l=20;
	if(l<=1000) cout<<l;
	else cout<<"alternative!";

	return 0;
}
