#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
string x,c;
char p[15];
//const char *cc;
char cp[100];
char *cc;
int main(){
    cin >> c;
    x=c+c;
    x.copy(cp,53,0);
    cc=cp;
    for (int k = 0; k <= 12; k++) {
        int i = 13;
        for (; i < 27; i++) {
            if ( cc[i]!=cc[i-1] &&(cc[i] == cc[25-i] || cc[i] == cc[24-i])) break;
            p[25-i] = cc[i];
        }i++;
        for (; i < 27; i++)
            p[26-i] = cc[i];
        if (p[0] == cc[26]) {
		F0(i, 13) cout << cc[i];
        cout << endl;cout << p;return 0;
		}
        cc++;
    }
    cout << "Impossible";
}
