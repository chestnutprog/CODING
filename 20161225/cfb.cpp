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
string s, t;
map<char, char> mp, mpd;
set<pair<char, char> > st;
int ans;
bool exchange(char a, char b){
    if (a == b) {
        mp.erase(a);
        return 1;
    }
    if (mp.count(a) == 0 || mp.count(b) == 0) {
        mp.erase(a);
        mp.erase(b);
        st.insert(make_pair(a, b));
        return 1;
    }
    if (mp[a] == b && mp[b] == a) {
        mp.erase(a);
        mp.erase(b);
        st.insert(make_pair(a, b));
        return 1;
    }
    st.insert(make_pair(a, b));
    mp[mpd[a]] = mp[a];
    mp.erase(a);
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin >> s >> t;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] != t[i]) {
            if ((mp.count(s[i]) && mp[s[i]] != t[i])||(mp.count(t[i]) && mp[t[i]] != s[i])) {
                cout << -1;
                return 0;
            } else if (!mp.count(s[i])) {
                mp[s[i]] = t[i];
                mp[t[i]] = s[i];
                mpd[t[i]] = s[i];
                ans++;
            }
        } else{
            if ((mp.count(s[i]) && mp[s[i]] != t[i])||(mp.count(t[i]) && mp[t[i]] != s[i])) {
                cout << -1;
                return 0;
            }
            mp[s[i]] = t[i];
        }

    }
    while (!mp.empty()) {
        exchange(mp.begin()->first, mp.begin()->second);
    }
    cout << st.size() << endl;
    for (set<pair<char, char> >::iterator x = st.begin(); x != st.end(); x++)
        cout << x->first << ' ' << x->second << endl;
}

