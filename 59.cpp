#include<cstdio>
#include<set>
#include<queue>
using namespace std;
queue<int> q;
set<int> s;
int m,n,ans;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(s.find(a)==s.end()){
			if(q.size()==m){
				s.erase(q.front());
				q.pop();
				s.insert(a);
				q.push(a);
				ans++;
			}
			else
			{
				s.insert(a);
				q.push(a);
				ans++;
			}
		}
	}
	printf("%d",ans);
} 
