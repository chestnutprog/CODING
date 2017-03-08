#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    scanf("%d", &n);
    if(n==0){
        printf("1\n");
        printf("0 0 0");
        return 0;
    }
    if(n==1){
        printf("1\n");
        printf("0 1 0");
        return 0;
    }
    if(n==2){
        printf("2\n");
        printf("0 1 1\n");
        printf("2 0 0");
        return 0;
    }
    int j = (n >> 1); int flag = 0;
    for (int i = 0; i <= n; i++) {
        ans++;
        j++;
        if (j + i >= n) {
            if (flag) break; flag = 1;
            j=(n-(n-(i+j)+i+1))&1;
        }
    }
    printf("%d\n", ans);
    j = (n >> 1); flag = 0;
    for (int i = 0; i <= n; i++) {
        printf("%d %d %d\n", i, j, n - (i + j));
        j++;
        if (j + i >= n) {
            if (flag) break; flag = 1;
            j=(n-(n-(i+j)+i+1))&1;
        }
    }
}