#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char a[40];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char d;
		do{
			d=getchar();
		}while(d=='\n');
		a[i]=d;
	}
	a[n+1]='\0';
	string b = a;
	sort(a,a+n);
	int i = 1;
	while(a!=b) {
		next_permutation(a,a+n);
		i++;
	}
	cout<<i<<endl;
} 
