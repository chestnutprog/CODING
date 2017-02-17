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
multimap<int,int> add, del;
set<int> server,timee，uses[100001];
int needsum[100001],id[100001];
int n, q;
int a,b;
int main(){
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for1(i, n){
        server.insert(i);
    }
    for1(i, q){
        cin>>a>>b>>needsum[i];
        timee.insert(a);timee.insert(b);
    }
    for(set<int>::iterator i = timee.begin();i!=timee.end();i++){
        for(multimap<int,int>::iterator j = del.find(*i);j->first==*i;j++){

        }
    }
}

