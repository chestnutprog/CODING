#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
bool p=0;
struct seg{
	int l,r;
	bool operator>(seg b){
	if(!p)return l>b.l;else return r>b.r;} 
};
__gnu_pbds::tree<seg,__gnu_pbds::null_type,std::less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T[4];
int n;
int main(){
	scanf("%d",&n);
}
