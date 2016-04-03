#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<int,__gnu_pbds::null_type,std::less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T;
int n;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        switch(a){
            case 1:T.insert(b);break;
            case 2:T.erase(b);break;
            case 3:printf("%d\n",T.order_of_key(b)+1);break;
            case 4:printf("%d\n",*T.find_by_order(b-1));break;
            case 5:printf("%d\n",*--T.lower_bound(b));break;
            case 6:printf("%d\n",*T.upper_bound(b));break;
        }
    }
}
