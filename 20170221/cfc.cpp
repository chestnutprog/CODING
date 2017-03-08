#include<bits/stdc++.h>
using namespace std;
/*
int n,k,x;
int a[100005];
int hashmin[1000003],hashmax[1000003];
bitset<1000003> used;
int hashhistory[100000];
int tot=-1;int hashs;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k>>x;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int j=0;j<n;j++)hashs=(hashs*61+a[j])%1000003;
    used[hashs]=1;
    hashhistory[++tot]=hashs;
    hashmax[hashs]=a[n-1];
    hashmin[hashs]=a[0];
    for(int i=0;i<k;i++){
        sort(a,a+n);hashs=0;
        for(int j=0;j<n;j++)a[j]^=x;
        for(int j=0;j<n;j++)hashs=(hashs*61+a[j])%1000003;
        if(used[hashs]){
            cout<<hashmax[hashhistory[k%tot]]<<' '<<hashmin[hashhistory[k%tot]];
            return 0;
        }else{
            used[hashs]=1;
            hashhistory[++tot]=hashs;
            hashmax[hashs]=a[n-1];
            hashmin[hashs]=a[0];
        }
    }
    cout<<a[n-1]<<' '<<a[0];
}
*/
int n,k,x,t,maxm=INT_MIN,minm=INT_MAX,t1,t2;
int num[2][1050];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)cin>>t,num[0][t]++;
    for(int i=1;i<=k;i++){
        memset(num[i&1],0,sizeof(num[0]));t=0;
        for(int l=0;l<1024;l++){
            if(t&1){
                t1=(num[(i&1)^1][l])>>1;
                t2=(num[(i&1)^1][l]+1)>>1;
            }else{
                t1=(num[(i&1)^1][l]+1)>>1;
                t2=(num[(i&1)^1][l])>>1;
            }
            num[i&1][l^x]+=t1;
            num[i&1][l]+=t2;
            t+=num[(i&1)^1][l];
        }
    }
    for(int i=0;i<1024;i++)
        if(num[k&1][i]){
            minm=min(minm,i);
            maxm=max(maxm,i);
        }
    cout<<maxm<<' '<<minm;
}