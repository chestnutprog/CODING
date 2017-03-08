#include<bits/stdc++.h>
using namespace std;
string s[500010];
int comp(int a,int b){
    int l=min(s[a].length(),s[b].length());int i;
    for(i=0;i<l;i++){
        if(s[a][i]<s[b][i])return i;else if(s[a][i]!=s[b][i])break;
    }
    if(i==l&&s[a].length()<s[b].length())return s[a].length();
    return -1;
}
int n;
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=n-1;i>0;i--){
        int t=comp(i,i-1);
        if(t!=-1){
            s[i-1].resize(t);
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}
