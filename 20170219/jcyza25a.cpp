#include<bits/stdc++.h>
using namespace std;
struct x{
    int a,b;
    bool operator<(const x &c)const{
        return a<c.a;
    }
};
int n;x a[10010];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i].a),a[i].b=i+1;
    stable_sort(a,a+n);
    for(int i=0;i<n;i++)printf("%d ",a[i].b);
    return 1;
}