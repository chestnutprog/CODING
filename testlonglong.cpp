#include<iostream>
using namespace std;
long long a,b;
int d,e;
int main(){
	cin>>d>>e;
	a=d,e=b;
	d=(d*e)%233333;
	a=a*b;
	cout<<a;
	cout<<d;
	return 0;
} 
