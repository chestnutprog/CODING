#include <bits/stdc++.h>
using namespace std;
#define MOD 9973
int f[1001][6][47];//模[2]余[3]有多少方案
int a[] = {1, 2, 3, 5, 7};
int b[] = {2, 3, 5, 7, 11, 47};
int powm(int a, int x,int p){
    int ans = 1;
    while (x) {
        if (x & 1) ans = (ans * a) % p;
        a = (a * a) % p;
        x >>= 1;
    }
    return ans;
}

int n;
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            f[1][j][a[i] % b[j]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int l = 1; l <= 46; l++)
            for (int j = 0; j < 5; j++)
                for (int k = 0; k < 6; k++) {
                    //f[i][k][(l+powm(10,i-1,b[k])*a[j])%b[k]]+=f[i-1][]
                }
    }
}