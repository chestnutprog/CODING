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
#define checko() if((!codd.size())){cout<<-1;return 0;}
#define checke() if((!ceven.size())){cout<<-1;return 0;}
using namespace std;
int n, m, t,ans;
multiset<int> nodd, neven;
set<int> codd, ceven;
set<int> odd, even;
set<int> orw,erw;
int p[200005];
void ppp(){
    if(odd.size()){
        cout<<*odd.begin()<<' ';
        odd.erase(odd.begin());
    }else{
        cout<<*even.begin()<<' ';
        even.erase(even.begin());
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for1(i, m){
        if (i & 1)
            ceven.insert(i);
        else
            codd.insert(i);
    }
    for1(i, n){
        cin >> t;p[i]=t;
        if (t & 1) {
            if (ceven.count(t)) ceven.erase(t);
            if (even.count(t)) neven.insert(t); else
                even.insert(t);
        } else {
            if (codd.count(t)) codd.erase(t);
            if (odd.count(t)) nodd.insert(t); else
                odd.insert(t);
        }
    }orw=odd;erw=even;
    odd.clear();even.clear();
    while(neven.size()){
        ans++;
        neven.erase(neven.begin());
        if(even.size()>odd.size()){
            checko();
            odd.insert(*codd.begin());
            codd.erase(codd.begin());
        }else{
            checke();
            even.insert(*ceven.begin());
            ceven.erase(ceven.begin());
        }
    }
    while(nodd.size()){
        ans++;
        nodd.erase(nodd.begin());
        if(even.size()>odd.size()){
            checko();
            odd.insert(*codd.begin());
            codd.erase(codd.begin());
        }else{
            checke();
            even.insert(*ceven.begin());
            ceven.erase(ceven.begin());
        }
    }
    while(odd.size()>even.size()){
        t=*--odd.end();ans++;
        odd.erase(t);
        if(even.size()>odd.size()){
            checko();
            odd.insert(*codd.begin());
            codd.erase(codd.begin());
        }else{
            checke();
            even.insert(*ceven.begin());
            ceven.erase(ceven.begin());
        }
    }
    while(odd.size()<even.size()){
        t=*--even.begin();ans++;
        even.erase(t);
        if(even.size()>odd.size()){
            checko();
            odd.insert(*codd.begin());
            codd.erase(codd.begin());
        }else{
            checke();
            even.insert(*ceven.begin());
            ceven.erase(ceven.begin());
        }
    }
    cout<<ans<<endl;
    for1(i,n){
        if(p[i]&1){
            if(erw.count(p[i])){
                cout<<p[i]<<' ';
                erw.erase(p[i]);
            }else{
                ppp();
            }
        }else{
            if(orw.count(p[i])){
                cout<<p[i]<<' ';
                orw.erase(p[i]);
            }else{
                ppp();
            }
        }
    }
    /*
    while (even.size() > odd.size()) {
        neven.insert(*(--even.end()));
        even.erase(*(--even.end()));
    }
    while (even.size() < odd.size()) {
        nodd.insert(*(--odd.end()));
        odd.erase(*(--odd.end()));
    }
    if (neven.size() <= codd.size() && nodd.size() <= ceven.size()) {
        cout << neven.size() + nodd.size() << endl;
        set<int>::iterator x = codd.begin();
        for (int i = 1; i <= (int)neven.size(); i++, x++) cout << *x << ' ';
        x = ceven.begin();
        for (int i = 1; i <= (int)nodd.size(); i++, x++) cout << *x << ' ';

    } else {
        cout << -1;
        cout << neven.size();
    }*/
}

