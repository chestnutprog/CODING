#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int len,sum,t,ma;
int dp[300010];
int main(){
    cin>>len>>sum;
    len--;
    ma=len*(len+1)>>1;
    t=(ma-sum)>>1;
    dp[0]=1;
    for(int i=1;i<=len;i++){
        for(int j=t;j>=i;j--){
            dp[j]=(dp[j-i]+dp[j])%100000007;
        }
    }
    if(dp[t]==0||(ma-sum)&1){cout<<"NIE";return 0;}
    cout<<dp[t];
}