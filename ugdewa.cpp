#include<cstdio>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
int T,n,a[100010];
deque<int> d;
set<int> s,sq;
int main(){
	freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		for(int i=0;i<n;i++){
				while((!d.empty())&&min(d.front(),d.back())<*s.begin()){
					if(d.front()>d.back()){
						printf("%d ",d.back());
						sq.erase(d.back());
						d.pop_back();
					}else{
						printf("%d ",d.front());
						sq.erase(d.front());
						d.pop_front();
					}
				}
				if(d.empty()||(min(d.front(),d.back()))>*s.begin()){
					sq.insert(a[i]);
					d.push_front(a[i]);
					s.erase(a[i]);
				}
		}
		while(!d.empty()){
			if(d.front()>d.back()){
				printf("%d ",d.back());
				sq.erase(d.back());
				d.pop_back();
			}else{
				printf("%d ",d.front());
				sq.erase(d.front());
				d.pop_front();
			}
		}
		printf("\n");
	}
}
