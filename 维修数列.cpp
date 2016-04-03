#include<cstdio>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<algorithm>
#define inf 0x3fffffff
#include<ext/rope>
#include<iostream>
#include<cstring>
using namespace std;
__gnu_cxx::rope<int > a,b,tmp;
int n,m,len;
int main(){
    scanf("%d%d",&n,&m);
    int t,t1,t2;
    for(int i=1;i<=n;i++){
    	//scanf("%d",&t);
        a.push_back(i);
        b.insert(0,i);
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);cout<<endl;
    for(int i=0;i<n;i++) printf("%d ",b[i]);cout<<endl;
    for(int i=1;i<=m;i++){
    	len = a.length();
		scanf("%d%d",&t,&t1);
		t--;t1=t1-t;
		tmp=a.substr(t,t1);
		a=a.substr(0,t)+b.substr(len-t-t1,t1)+a.substr(t+t1,len-t-t1);
		b=b.substr(0,len-t-t1)+tmp+b.substr(len-t,t1);
		for(int i=0;i<n;i++) printf("%d ",a[i]);cout<<endl;
		for(int i=0;i<n;i++) printf("%d ",b[i]);cout<<endl;
	}
	
    return 0;
}
