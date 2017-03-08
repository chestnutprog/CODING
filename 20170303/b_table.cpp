#pragma GCC optimize ("O4")
#include <bits/stdc++.h>
using namespace std;
int a[52];
int main(){
    ios::sync_with_stdio(0);
    for(int i=1;i<=50;i++){
        for(int j=0;j<i;j++){
            a[j]=j+1;
        }
        int num=0;
        do{
            bool c=1;
            for(int j=0;j<i-1;j++)if(abs(a[j]-a[j+1])==1)c&=0;
            num+=c;
        }while(next_permutation(a,a+i));
        cout<<num<<endl;
    }
}