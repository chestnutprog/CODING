#include <bits/stdc++.h>
using namespace std;
int a[]={1,2,3,5,7};
int b[]={2,3,5,7,11,47};
long long pow1[20];
vector<long long> x[2];
long long ans;
int main(){
    ios::sync_with_stdio(0);
    pow1[0]=1;
    for(int i=1;i<=19;i++)pow1[i]=pow1[i-1]*10;
    for(int i=0;i<5;i++)x[0].push_back(a[i]);
    for(int i=1;i<=10;i++){
        ans=0;
        for(int j=0;j<(int)x[(i&1)^1].size();j++){
            bool c=1;
            for(int k=0;k<6;k++)if(x[(i&1)^1][j]%b[k]==0)c&=0;
            ans+=c;
        }
        cerr<<ans<<endl;
        for(int j=0;j<5;j++){
            for(int k=0;k<(int)x[(i&1)^1].size();k++){
                x[i&1].push_back(x[(i&1)^1][k]+pow1[i]*a[j]);
            }
        }
        x[(i&1)^1].clear();
    }
}