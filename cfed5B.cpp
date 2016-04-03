#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
long long t,t1;
vector<long long> x;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		t1=0x7ffffffffffffff;
		for(int j=1;j<=m;j++){
			scanf("%I64d",&t);
			t1=min(t,t1);
		}
		x.push_back(t1);
	}
	sort(x.begin(),x.end());
	printf("%I64d",*--x.end());
}
