#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int x[1010],y[2010],t,ans1,ans2,c;
multiset<int> s;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)x[i+1]=a[i]-'0';
    for(int i=0;i<n;i++)y[i+1]=b[i]-'0';
    sort(x+1,x+n+1);sort(y+1,y+n+1);c=y[0];
    //for(int i=0;i<n;i++)if(x[i]>y[i])ans1++;
    //for(int i=n;i<2*n;i++)y[i]=y[i-n];
    //for(int i=0;i<)
    //for(int i=0;i<n;i++)if(y[i]==c&&x[i]>=y[i])y[i]=10;else break;
    //sort(y,y+n);
    //for(int i=0;i<n;i++)if(y[i]!=10){if(x[i]<y[i])ans2++;}else break;
    //cout<<ans1<<endl<<ans2;
    int j=n;
    for(int i=n;i>=1;i--){
        while(x[j]>y[i] && j>=1)j--;
        if(j>=1)ans2++,j--;
    }
    cout<<n-ans2<<endl;
    ans2=0;j=n;
    for(int i=n;i>=1;i--){
        while(x[j]>=y[i] && j>=1)j--;
        if(j>=1)ans2++,j--;
    }
    cout<<ans2;
}