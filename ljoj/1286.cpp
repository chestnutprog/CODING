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
#define INF 0x7fffffff
int n;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
struct s{
  int x;
bool operator<(s b)const{
  return x<=b.x;
}
};
__gnu_pbds::tree<s,__gnu_pbds::null_type,std::less<s>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        T.insert((s){a});
        printf("%d\n",T.order_of_key((s){a}));
        }
}
