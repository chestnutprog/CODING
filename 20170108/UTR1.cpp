
#include <cstdio>
#include <iostream>

#define lowbit(i) (i & (-i))

using namespace std;

int readint(){
    int sign = 1, n = 0; char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') sign = -1; c = getchar();
    }
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0'; c = getchar();
    }
    return sign * n;
}

const int Nmax = 200100;

int N, Q;

long long delta[Nmax]; // delta的前缀和
long long deltai[Nmax]; // delta * i的前缀和
long long sum[Nmax]; // 原始前缀和
int querys[Nmax];

long long Query(long long *array, int pos){
    long long temp = 0ll;
    while (pos > 0) {
        temp += array[pos];
        pos -= lowbit(pos);
    }
    return temp;
}

void Update(long long *array, int pos, int x){
    while (pos <= N) {
        array[pos] += x;
        pos += lowbit(pos);
    }
}

const int x = 1;
int main(){
    N = readint();

    for (int i = 1; i <= N; ++i) {
        int l = readint();
        int r = i - 1;
        printf("%d %d\n", l, r);
        if (l <= r) {
            Update(delta, l, x);
            Update(delta, r + 1, -x);
            Update(deltai, l, x * l);
            Update(deltai, r + 1, -x * (r + 1));
        }
        Update(delta, i, i);
        Update(delta, i + 1, -i);
        Update(deltai, i, i * i);
        Update(deltai, i + 1, -i * (i + 1));
    }
    for (int i = 1; i <= N; i++) {
        long long suml = sum[i - 1] + i * Query(delta, i - 1) - Query(deltai, i - 1);
        long long sumr = sum[i] + (i + 1) * Query(delta, i) - Query(deltai, i);
        printf("%lld ", sumr - suml);
    }
    //Q = readint();
    /*
       while(Q--)
       {
            int sign = readint();
            if(sign == 1) // 修改：把[l, r]区间均加上x
            {
                    int l = readint(), r = readint(), x = readint();

            }
            else // 查询：[l, r]区间和
            {
                    int l = readint(), r = readint();
                    long long suml = sum[l - 1] + l * Query(delta, l - 1) - Query(deltai, l - 1);
                    long long sumr = sum[r] + (r + 1) * Query(delta, r) - Query(deltai, r);
                    printf("%lld\n", sumr - suml);
            }
       }
     */

    return 0;
}