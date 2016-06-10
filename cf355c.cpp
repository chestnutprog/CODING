#include <cstdio>
#include <algorithm>
#include<set>
#include<cmath>
#include<cstring>
using namespace std;
int n,h,k;
long long ans=1;
int len;
char a[100010];
int pwr[70];
#define MOD (1000000007)
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int get(char x){
    if('0'<=x&&'9'>=x)return x-'0';
    if('A'<=x&&'Z'>=x)return x-'A'+10;
    if('a'<=x&&'z'>=x)return x-'a'+36;
    if('-'==x)return 62;
    if('_'==x)return 63;
}
int count(int x){
  int an=0;
  while(x){x=x^(x&-x);an++;}
  return an;
}
int main(){
    freopen("input.txt","r",stdin);
    pwr[0]=1;
    pwr[1]=3;
    F(i,2,64)pwr[i]=pwr[i-1]*3%MOD;
    scanf("%s",a);
    len = strlen(a);
    F0(i,len){
        ans=ans*pwr[6-count(get(a[i]))]%MOD;
    }
    printf("%I64d",ans);
}
