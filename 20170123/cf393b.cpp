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
ll n, m, k;
ll l, r;
ll ans, p;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> k; l = r = k; m -= n;
    ans =max((long long)((m - sqrt(m)) / n - 100),1LL);
    //l -= ans - 1; r += ans - 1;
     m -= (ans - 1) * n;
    // cout<<ans;
    //cout << ans << endl;
    /*p=sqrt(m);m-=p*p;
       if(k-p+1<1)m+=(k-p)*(k-p+1)/2;
       if(k+p-1>n)m+=(n-k-p+1)*(n-k-p+2)/2;
       l-=p,r+=p;
       ans=1+p;

     */
    //cerr<<m;
    //ans=1;
    while ((k - max(l, 1LL)) + (min(r, n) - k) < m) {
        m -= (k - max(l, 1LL)) + (min(r, n) - k) + 1;
        l--; r++;
        ans++;
    }
    cout << ans;
}

