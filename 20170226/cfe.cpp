#include<bits/stdc++.h>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int n,m,cc[5002],ts;
//unordered_map<string,int> mp;
trie<string,int> mp;
string ans1,ans2,vars[5002],t,p1[5002],p2[5002];
bool ps[5002];
inline int calc(int j){
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)if(ps[i])mp[vars[i]]=p1[i][j]-'0';
    mp["?"]=0;
    for(int i=1;i<=n;i++){
        if(!ps[i]){
            switch (cc[i]) {
                case 0:
                    ts=mp[p1[i]]|mp[p2[i]];
                    break;
                case 1:
                    ts=mp[p1[i]]^mp[p2[i]];
                    break;
                case 2:
                    ts=mp[p1[i]]&mp[p2[i]];
                    break;
            }
            mp[vars[i]]=ts;
            ans1+=ts;
        }
    }
    mp["?"]=1;
    for(int i=1;i<=n;i++){
        if(!ps[i]){
            switch (cc[i]) {
                case 0:
                    ts=mp[p1[i]]|mp[p2[i]];
                    break;
                case 1:
                    ts=mp[p1[i]]^mp[p2[i]];
                    break;
                case 2:
                    ts=mp[p1[i]]&mp[p2[i]];
                    break;
            }
            mp[vars[i]]=ts;
            ans2+=ts;
        }
    }
    if(ans1==ans2)return 0;
    if(ans1>ans2)return 1;
    return 2;
}//0取0取1都一样 1取1小 2取1大
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>vars[i]>>t;
        cin>>p1[i];
        if(p1[i][0]=='0'||p1[i][0]=='1'){
            ps[i]=1;
        }else{
            cin>>t;
            switch (t[0]) {
                case 'O':
                    cc[i]=0;
                    break;
                case 'X':
                    cc[i]=1;
                    break;
                case 'A':
                    cc[i]=2;
                    break;
            }
            cin>>p2[i];
        }
    }
    for(int j=0;j<m;j++){
        switch (calc(j)) {
            case 0:
                ans1+='0',ans2+='0';
                break;
            case 1:
                ans1+='0',ans2+='1';
                break;
            case 2:
                ans1+='1',ans2+='0';
                break;
        }
    }
    cout<<ans2<<endl<<ans1;
}