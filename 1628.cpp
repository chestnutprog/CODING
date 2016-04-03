#include<stack>
#include<cstdio>
using namespace std;
stack<int> a;
int n,w,ans;
int main(){
	scanf("%d%d",&n,&w);
	a.push(0);
	ans =n;
	for(int i=1;i<=n;i++){
		int c,b;
		scanf("%d%d",&c,&b);
		while (b<a.top()) a.pop();
		if(b==a.top())ans--;
		else a.push(b);
	}
	printf("%d",ans);
}
