#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define F1(i,n) for(int i=1;i<=n;i++)
using namespace std;
string s;
int a,b;
int main(){
    ios::sync_with_stdio(0);
    getline(cin,s);
    for(int i=0;i<(int)s.length();i++){
        switch (s[i]) {
            case 'R':a++;
            break;
            case 'U':b++;
            break;
            case 'D':b--;
            break;
            case 'L':a--;
            break;
        }
    }
    if((abs(a)+abs(b))%2==0)printf("%d",(abs(a)+abs(b))/2);
    else printf("-1");
}