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
int x[3], y[3];
set<pair<int, int> > s;
int main(){
    ios::sync_with_stdio(0);
    for0(i, 3) cin >> x[i] >> y[i];
    //cout<<3<<endl;
    s.insert(make_pair((x[1] - x[0]) + (x[2] - x[0]) + x[0], (y[1] - y[0]) + (y[2] - y[0]) + y[0]));
    s.insert(make_pair((x[0] - x[1]) + (x[2] - x[1]) + x[1], (y[0] - y[1]) + (y[2] - y[1]) + y[1]));
    s.insert(make_pair((x[1] - x[2]) + (x[0] - x[2]) + x[2], (y[1] - y[2]) + (y[0] - y[2]) + y[2]));
    cout << s.size() << endl;
    for (set<pair<int, int> >::iterator i = s.begin(); i != s.end(); i++)
        cout << i->first << ' ' << i->second << endl;
}

