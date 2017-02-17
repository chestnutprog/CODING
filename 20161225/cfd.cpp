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
int tot;
struct Trie {
    int id;
    Trie *go[26];
    Trie(){
        id = 0;
        memset(go, 0, sizeof(go));
    }
} root;
int n, k;
int getid(string &x){
    Trie *now = &root;
    for (int i = 0; i < (int)x.length(); i++) {
        if (!now->go[x[i] - 'a']) now->go[x[i] - 'a'] = new Trie();
        now = now->go[x[i] - 'a'];
    }
    if (!now->id) now->id = ++tot;
    return now->id;
}

int getidr(string &x){
    Trie *now = &root;
    for (int i = (int)x.length() - 1; i >= 0; i--) {
        if (!now->go[x[i] - 'a']) now->go[x[i] - 'a'] = new Trie();
        now = now->go[x[i] - 'a'];
    }
    if (!now->id) now->id = ++tot;
    return now->id;
}

vector<int> p[100001];
string s;
int t, id, rid;
bool cent[100001];
int used[100001];
int rrid[100001];
long long ans;
int insertk;
int makkkk;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for1(i, n){
        cin >> s >> t;
        id = getid(s);
        rid = getidr(s);
        rrid[id] = rid;
        if (rid == id)
            cent[id] = 1;
        p[id].push_back(t);
    }
    for1(id, tot){
        sort(p[id].begin(), p[id].end(),greater<int>());
    }
    for1(id, tot){
        if (cent[id]) {
            for0(i, (int)p[id].size()){
                if (i + 1 < (int)p[id].size()) {
                    if (p[id][i] + p[id][i + 1] > 0) {
                        ans += p[id][i] + p[id][i + 1];
                        if(p[id][i + 1]<0)makkkk = min(makkkk,p[id][i+1]);
                        i++;
                        used[id] = i + 1;
                    } else
                        break;
                }
            }
            if (used[id] < (int)p[id].size())
                insertk = max(insertk, p[id][used[id]]);
        } else {
            if (!used[id])
                for0(i, (int)p[id].size()){
                    if (i < (int)p[rrid[id]].size())
                        if (p[id][i] + p[rrid[id]][i] > 0)
                            ans += p[id][i] + p[rrid[id]][i];
                    used[id] = i+1;
                    used[rrid[id]]=i+1;
                }
        }
    }
    cout << ans + max(insertk,-makkkk);
}

