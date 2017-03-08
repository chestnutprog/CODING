#include<bits/stdc++.h>
using namespace std;
#define sum(i) (a[i]+b[i])
#define mid(i) (sum(i)>>1)
int a[6],b[6],n,t;
int swaps;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t,a[t]++;
    for(int i=1;i<=n;i++) cin>>t,b[t]++;
    for(int i=1;i<=5;i++){
        if(sum(i)&1){
            cout<<-1<<endl;
            return 0;
        }
        swaps+=abs(a[i]-mid(i));
    }
    cout<<(swaps>>1);
}