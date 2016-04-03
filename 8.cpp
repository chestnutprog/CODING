#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<long long,int> hh;
int n,q;
long long an=0;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		hh.insert(make_pair(an,i));
		int b;
		scanf("%d",&b);
		an+=b;
	}
	hh.insert(make_pair(an,n+1));
	for(int i=0;i<q;i++) {
		int b;
		scanf("%d",&b);
		if((hh.lower_bound(b)->first)==b){
		    printf("%d\n",hh.lower_bound(b)->second);
            continue;
		}
		printf("%d\n",(hh.upper_bound(b))->second-1);
	}
}

