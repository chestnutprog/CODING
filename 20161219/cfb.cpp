#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#define inf 1000000000
#define maxn 500 + 100
#define maxm 500 + 100
#define eps 1e-10
#define ll long long
#define pa pair < int, int >
#define for0(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define for2(i, x, y) for (int i = (x); i <= (y); i++)
#define for3(i, x, y) for (int i = (x); i >= (y); i--)
#define mod 1000000007
using namespace std;
int a, g, c, t, n;
int da, dg, dc, dt;
string x;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> x;
    for0(i, n){
        switch (x[i]) {
            case 'A': a++; break;
            case 'C': c++; break;
            case 'G': g++; break;
            case 'T': t++; break;
        }
    }
    da = n / 4 - a;
    dc = n / 4 - c;
    dg = n / 4 - g;
    dt = n / 4 - t;
    if (n % 4 || da < 0 || dc < 0 || dg < 0 || dt < 0) {
        cout << "==="; return 0;
    }
    for0(i,n){
        if(x[i]=='?'){
            if(da){
                cout<<'A';
                da--;
                continue;
            }
            if(dc){
                cout<<'C';
                dc--;
                continue;
            }
            if(dg){
                cout<<'G';
                dg--;
                continue;
            }
            if(dt){
                cout<<'T';
                dt--;
                continue;
            }
        }else{
            cout<<x[i];
        }
    }
    cout<<endl;
}

