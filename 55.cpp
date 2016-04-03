#include<cstdio>
#include<iostream>
using namespace std;
char a[1010];
int k;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>k>>a;
	int i=0,count=1;
	char before='\0';
	while(a[i]!='\0'){if(before==a[i]){if(++count==k){cout<<a[i];return 0;}}else{count=1;before=a[i];}i++;}
    cout<<"No";
}


