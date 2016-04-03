#include<cstdio>
#include<fstream>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define SN 10000
using namespace std;
__gnu_pbds::tree<double,int,std::less<double>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> T;
int n;
void ins(int x){
	for(int i=1;i<=SN;i++)
		if(T.find(x+i/10000.0)==T.end()){
			T.insert(make_pair(x+i/10000.0,x));
			return;
		}
}
 
void era(int x){
	for(int i=1;i<=SN;i++)
		if(T.find(x+i/10000.0)!=T.end()){
			T.erase(x+i/10000.0);
			return;
		}
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
 
        switch(a){
            case 1:ins(b);break;
            case 2:era(b);break;
            case 3:printf("%d\n",T.order_of_key(b)+1);break;
            case 4:printf("%d\n",(*T.find_by_order(b-1)).second);break;
            case 5:printf("%d\n",(*--T.lower_bound(b)).second);break;
            case 6:printf("%d\n",(*T.upper_bound(b+0.999)).second);break;
 
        }
    }
}
