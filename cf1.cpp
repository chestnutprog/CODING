#include<iostream>
#include<bitset>
#include<cstring>
#include<algorithm>
using namespace std;
bitset<64> a;
long long long aaaa; 
unsigned long long s[10000],x,y;
int tot,ans;
int main(){
	for(int i=0;i<64;i++){
		a.reset();
		for(int j=0;j<i;j++)a[j]=1;
		for(int j=i+1;j<64;j++)a[j]=1,s[++tot]=a.to_ullong();
	}
	sort(s+1,s+1+tot);
	cin>>x>>y;	
	for(int i=1;i<=tot;i++){
		if(s[i]>=x&&ans==0)	ans=i;
		if(s[i]==y){cout<<i-ans+1<<endl; return 0;}
		if(s[i]>y){cout<<i-ans;return 0;}
	}
	
}
