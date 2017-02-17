#include <cstdio>
#include <iostream>
using namespace std;
int n;int f=10;int ans;
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=3;i<=n;i++){
		ans+=f;f*=11;
	}
	cout<<ans;
}