#include<iostream>
#include<string>

using namespace std;
int main(){
 string a,b,c;
 cin>>a>>b>>c;
 while(a.length()<8)a=" "+a;
while(b.length()<8)b=" "+b;
while(c.length()<8)c=" "+c;
cout<<a<<" "<<b<<" "<<c<<endl;

return 0;
} 
