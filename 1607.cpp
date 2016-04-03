#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],ans[1000010],b[1000010],mx;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(a[i],mx);
		b[a[i]]++;
		}
	for(int i=1;i<=mx;i++)
	if(b[i])
		for(int j=i;j<=mx;j+=i)
		ans[j]+=b[i];
	for(int i=1;i<=n;i++)printf("%d\n",ans[a[i]]-1);	
}
