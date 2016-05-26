#include <algorithm>
#include<cstdio>
using namespace std;
long long MOD;
long long x, m, c, T;
long long pow4(long long a, long long b){
    long long r = 1, base = a;
    while (b != 0) {
        if (b & 1) {
            r = (r * base) % MOD;
        }
        base = (base * base) % MOD;
        b >>= 1;
    }
    return r;
}

int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
      scanf("%I64d%I64d%I64d%I64d",&x,&m,&MOD,&c);
      //cout<<( ( (pow4(10, m) - 1 + MOD) * x *mod_reverse(9,MOD)) % MOD+MOD)%MOD;
      printf("Case #%d:\n",i);
      printf("%s\n", (( (pow4(10,m)-1) *x+MOD) %MOD ==(c*9)%MOD)?"Yes":"No");
    }
}
