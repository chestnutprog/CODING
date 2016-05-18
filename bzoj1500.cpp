#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
template <class Node_CItr , class Node_Itr ,
class Cmp_Fn , class _Alloc >
struct my_node_update: __gnu_pbds::tree_order_statistics_node_update {
virtual Node_CItr node_begin() const = 0;
virtual Node_CItr node_end() const = 0;
typedef int metadata_type;
};
__gnu_pbds::tree<double,int,std::less<double>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T;

int main(){

}
