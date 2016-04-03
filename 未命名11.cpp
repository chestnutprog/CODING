#include<iostream>
using namespace std;
long long a,b;
int main(){
	cin>>a>>b;
	int ans=0;
	for(int i=1;i<=60;++i){
	long long ones=(1LL<<(i+1))-1;
	for(int j=0;j<i;++j){
		long long test =ones- (1LL<<j);
		if(test>=a&&test<=b)++ans;
	}}
	cout<<ans;
} 
