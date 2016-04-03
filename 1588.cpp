#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<algorithm>
#define inf 0x3fffffff
using namespace std;
__gnu_pbds::tree<int,__gnu_pbds::null_type,std::less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T;
int n,a,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(scanf("%d",&a)==EOF)a=0;
		if(i!=1)
		{
        int t1=*--T.lower_bound(a),t2=*T.lower_bound(a);
        if(T.lower_bound(a)==T.begin())t1=-inf;
        if(T.lower_bound(a)==T.end())t2=inf;
        ans+=min(a-t1,t2-a);
		}else{ans+=a;}
        T.insert(a);
    }
    printf("%d",ans);
    return 0;
}
