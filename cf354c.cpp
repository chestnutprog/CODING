#include <bits/stdc++.h>
#define si(n) scanf("%d", &n);
#define pi(n) printf("%d\n", n);
#define pl(n) printf("%lld\n", n);
#define sl(n) scanf("%lld", &n);
#define pd(n) printf("%lf\n", n);
#define ss(s) scanf("%s", s);
#define ps(s) printf("%s\n", s);
#define ll long long
#define mod 1000000009
#define b 1000000007
#define pb push_back
#define maxn 100005
#define maxm 1e9
#define pii pair < int, int >
using namespace std;
char s[maxn];
int n, k;
int p[maxn];
int check(int len){
    int counta = p[len];
    //for (int i = 0; i < len; i++) {
    //    if (s[i] == 'a')
    //        counta++;
    //}
    if (counta + k >= len || (len - counta) + k >= len) {
        return 1;
    }

    for (int i = 1; i <= (n - len); i++) {
        if (s[i - 1] == 'a') {
            counta--;
        }
        if (s[i + len - 1] == 'a') {
            counta++;
        }

        if (counta + k >= len || (len - counta) + k >= len) {
            return 1;
        }
    }
    return 0;
}

int main(){
    si(n); si(k);
    ss(s);
    for(int i=1;i<=n;i++)p[i]=p[i-1]+s[i]=='a';
    int low = 0;
    int high = n;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    if (check(high)) {
        pi(high);
    } else {
        pi(low);
    }
    return 0;
}
