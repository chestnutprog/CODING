#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int n,ans;
string x;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x;
    int a=0,b=n-1;
    while(x[a++]=='<')ans++;
    while(x[b--]=='>')ans++;
    //if(x[0]=='<'){cout<<1<<endl;return 0;}
    //if(x[n-1]=='>'){cout<<n<<endl;return 0;}
    cout<<ans<<endl;return 0;
}