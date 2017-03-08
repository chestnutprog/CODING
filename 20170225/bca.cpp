#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
map<string, multiset<int> > mp;
int T; int n;
string x; int t; int ans;
int main(){
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x >> t;
            mp[x].insert(t);
        }
        for (auto i = mp.begin(); i != mp.end(); i++) {
            int k = 1;
            for (auto j = i->second.rbegin(); j != i->second.rend() && k <= 2; j++, k++)
                ans += *j;
        }
        cerr << ans << endl;
        ans=0;
        mp.clear();
    }
}