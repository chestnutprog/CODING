#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
string t,p;
int a[200005],temp;
#define mid ((l+r)>>1)
#define checkk if(j==(int)t.size())break
bool isp(int pos){
    int j=0,i=0;
    for(;i<(int)p.size()&&j<(int)t.size();i++,j++){
        while(j<(int)t.size()&&(a[j+1]<=pos||p[i]!=t[j]))j++;
        checkk;
    }
    return i==(int)p.size();
}
int main(){
    cin>>t>>p;
    for(int i=1;i<=(int)t.size();i++){
        cin>>temp;
        a[temp]=i;
    }
    int l=0,r=(int)t.size();
    while(l<r){
        if(isp(mid))l=mid+1;else r=mid;
    }
    int x=l-2;
    for(;isp(x);x++);
    cout<<x-1;
}