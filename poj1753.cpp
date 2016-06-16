#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <bitset>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int v[1<<16];
const int x[]={
  0b1100100000000000,
  0b1110010000000000,
  0b0111001000000000,
  0b0011000100000000,
  0b1000110010000000,
  0b0100111001000000,
  0b0010011100100000,
  0b0001001100010000,
  0b0000100011001000,
  0b0000010011100100,
  0b0000001001110010,
  0b0000000100110001,
  0b0000000010001100,
  0b0000000001001110,
  0b0000000000100111,
  0b0000000000010011,
};
int n;
struct node{
    int state;
    node * go[16];
};
int ans=0x7fffffff;
char s[5];
queue<int > q;
int main(){
    int t=0;
    F0(i,4){
      scanf("%s",s);
      F0(j,4)t|=(s[j]=='b')<<(15-4*i-j);
    }
    q.push(t);
    v[t]=0;
    while(!q.empty()){
        t=q.front();
        int deep=v[q.front()];q.pop();
        if(t==0||t==0b1111111111111111){ans=min(ans,deep);break;}
        F0(i,16)
          if(v[t^x[i]]==0){q.push(t^x[i]);v[t^x[i]]=deep+1;}
    }
    printf(ans==0x7fffffff?"Impossible":"%d",ans);
}
