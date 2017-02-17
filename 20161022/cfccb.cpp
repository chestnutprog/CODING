#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
long long n;
char p;
int main(){
    cin>>n>>p;
    cout<<((n-1)/4)*16+((n-1)%2)*7+((('f'-p)>2)?(p-'a')+3:'f'-p)+1;
}