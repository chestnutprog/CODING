#include<bits/stdc++.h>
using namespace std;
int a[20],n;
double ans=0;
#define S0 0b111111111111
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int S=S0;S;S=S0&(S-1)){
        int num = __builtin_popcount(S);
        if(num <= 2)continue;
        int x = num>>1;
        double sum=0,med;
        if(num&1){
            for(int p=S;p;p-=(p&-p)){
                sum+=a[(int)log2(p&-p)];
                if(__builtin_popcount(p)==x+1)med=a[(int)log2(p&-p)];
            }
        }else{
            for(int p=S;p;p-=(p&-p)){
                sum+=a[(int)log2(p&-p)];
                if(__builtin_popcount(p)==x+1)med=a[(int)log2(p&-p)];
                if(__builtin_popcount(p)==x)med+=a[(int)log2(p&-p)],med/=2.0;
            }
        }
        if(sum/num-med>ans){
            printf("%d\n",S);
        }
        ans=max(ans,sum/num-med);
    }
    printf("%.4f",ans);
}