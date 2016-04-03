#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned int n,m,a[100010],tot,pun[1000100],ans,ansb;
int main(){
	scanf("%u%u",&n,&m);
	memset(a,-1,sizeof(a));
	for(unsigned int i=0;i<n;i++)scanf("%u",&a[i]);
	sort(a,a+n);
	int j=0;
	for(unsigned int i=1;ans+i<=m;i++){
		if(i==a[j]){
			j++;
		}else{
			ans+=i;
			pun[++ansb]=i;
		}
	}
	printf("%u\n",ansb);
	for(unsigned int i=1;i<=ansb;i++)printf("%u ",pun[i]);
}
