#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
using namespace __gnu_pbds;
template <class Node_CItr , class Node_Itr ,
class Cmp_Fn , class _Alloc >
struct my_node_update {
virtual Node_CItr node_begin() const = 0;
virtual Node_CItr node_end() const = 0;
typedef int metadata_type;
};
tree<double,int,std::less<double>,rb_tree_tag,tree_order_statistics_node_update> T;

int main(){

}
