#include <cstdio>
#include <set>
#include<iostream>
using namespace std;
int n, t;
struct q{
  int x,time;
  bool operator <(const q s)const{return x<s.x;}
};
set<q> T;
int main(){
    scanf("%d%d", &n,&t);
    T.insert((q){t,1});
    T.insert((q){1000000000,1});
    T.insert((q){-1000000000,1});
    for (int i = 2; i <= n; i++) {
        scanf("%d", &t);
        q a=*--T.lower_bound((q){t,i});
        q b=*T.lower_bound((q){t,i});
        if (b.x == 1000000000) printf("%d ", a.x);
		    else if (a.x == -1000000000) printf("%d ", b.x);
	      else printf("%d ", a.time < b.time ? b.x : a.x);
        T.insert((q){t,i});
    }
}
