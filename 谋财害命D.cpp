#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int n;
map<string, int> m;
string s;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        printf("%d\n", m[s]++);
    }
}
