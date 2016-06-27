#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
long long n,x,t,f;
char o[3];
int main(){
  scanf("%I64d%I64d",&n,&x );
  F1(i,n){
    scanf("%s%I64d",o,&t);
    if(o[0]=='+'){
      x+=t;
    }else{
      if(x>=t){
        x-=t;
      }else{
          f++;
      }
    }
  }
  printf("%I64d %I64d",x,f);
}
