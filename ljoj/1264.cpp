#include <cstdio>
#include <climits>
#include <cstring>

#define MAXN 30

//#define int64 long long
typedef long long int64;
int a[MAXN];
int64 f[MAXN][MAXN];
int root[MAXN][MAXN];

void print(int l, int r){
    int k = root[l][r];
    if(l > r) return;
    printf("%d ", k + 1);
    print(l, k - 1);
    print(k + 1, r);
}

int main(){
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);

    for(int i = 0; i < n; i++) f[i][i] = a[i], root[i][i] = i;

    for(int len = 1; len < n; len++){
        for(int l = 0; l < n - len; l++){
            int r = l + len;
            int64 &ans = f[l][r];

            ans = INT_MIN;
            for(int k = l; k <= r; k++){
                int64 lScore = l <= k - 1 ? f[l][k - 1] : 1;
                int64 rScore = k + 1 <= r ? f[k + 1][r] : 1;
                int64 score = lScore * rScore + (int64)a[k];

                if(score > ans) ans = score, root[l][r] = k;
            }
        }
    }

    printf("%lld\n", f[0][n - 1]);
    print(0, n - 1);

    return 0;
}
