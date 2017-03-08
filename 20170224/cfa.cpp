#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[][3] = {0,1,2 ,1,0,2, 1,2,0, 2,1,0, 2,0,1 ,0,2,1};
string p;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>x;
    cout<<a[(n%6)][x];
}