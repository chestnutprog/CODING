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
int n, k, a, b, t=-1;
deque<char> q;
int main(){
    q.push_back('\0');
    ios::sync_with_stdio(0);
    cin >> n >> k >> a >> b;
    for1(i, n){
        char last = q.back();
        if (t < k - 1) {
            if (a > b) {
                q.push_back('G'); a--;
            } else {
                q.push_back('B'); b--;
            }
        } else {
            if (last == 'B') {
                q.push_back('G'); a--;
            } else {
                q.push_back('B'); b--;
            }
        }
        if (last == q.back()) t++; else t = 0;
    }
    if (a == 0 &&
        b == 0) for (deque<char>::iterator i = ++q.begin(); i != q.end(); i++) cout << *i; else cout << "NO";
}

