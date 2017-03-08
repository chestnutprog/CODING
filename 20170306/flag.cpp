#include <bits/stdc++.h>
using namespace std;
#define pr pair < int, int >
#define mp(a, b) make_pair(a, b)
#define mid ((l + r) >> 1)
set<pr >s;
set<int> ss;
int a[2][20005];
short v[20005];
ostream& operator,(ostream& os,int x){os<<x<<' ';return os;}
ostream& operator,(ostream& os,string x){os<<x<<' ';return os;}
bool flagkp(int xl,int pp){
    ss.clear();ss.insert(INT_MAX);ss.insert(INT_MIN);
    memset(v, 0, sizeof(v));
    v[0] = pp+1;
    int now = a[pp][0], nowp = 0;
    int nowl = now;
    for (auto x = s.upper_bound(mp(now, nowp)); x != s.end(); x++) {
        now = x->first, nowp = x->second;
        if (v[nowp]) {
            if (a[v[nowp] - 1][nowp] == now) {
                if (abs(now - nowl) < xl)
                    return 0;
                nowl = now;
            }
            continue;
        }
        if (abs(now - nowl) >= xl && abs(now-*ss.upper_bound(now)) >= xl) {
            v[nowp] = (a[0][nowp] != now) + 1;
            nowl = now;
        } else
            v[nowp] = (a[0][nowp] == now) + 1;
        ss.insert(a[v[nowp]-1][nowp]);
        cerr,"puts",nowp,"at",a[v[nowp]-1][nowp],"\n";
    }
    now = a[pp][0], nowp = 0, nowl = now;
    for (auto x = --s.lower_bound(mp(now, nowp)); x != s.end(); x--) {
        now = x->first, nowp = x->second;
        if (v[nowp]) {
            if (a[v[nowp] - 1][nowp] == now) {
                //cerr,now,nowl,"\n";
                if (abs(now - nowl) < xl)
                    return 0;
                nowl = now;
            }
            continue;
        }
        if (abs(now - nowl) >= xl && abs(now-*--ss.lower_bound(now)) >= xl) {
            v[nowp] = (a[0][nowp] != now) + 1;
            nowl = now;
        } else
            v[nowp] = (a[0][nowp] == now) + 1;
        ss.insert(a[v[nowp]-1][nowp]);
        cerr,"puts",nowp,"at",a[v[nowp]-1][nowp],"\n";
    }
    return 1;
}
bool flagok(int xl){
    return (flagkp(xl,1)|flagkp(xl,0));
    //return flagkp(xl,1);
}

int n;
int main(){
    freopen("flag.in", "r", stdin);
    freopen("flag.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[0][i], &a[1][i]);
        s.insert(mp(a[0][i], i));
        s.insert(mp(a[1][i], i));
    }
    int l = 0, r = 1000000005;
    while (l < r) {
        if (flagok(mid)) l = mid + 1; else r =+ mid;
    }
    for (l -= 3; flagok(l); l++);
    cout << l - 1;
    //cout << flagkp(10,0);
}