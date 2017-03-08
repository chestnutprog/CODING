#include<bits/stdc++.h>
using namespace std;
int N=12;
int X=100;
int main(){
    ios::sync_with_stdio(0);
    srand(time(0));
    cout<<N<<endl;
    for(int i=1;i<=N;i++){
        cout<<rand()%X+1<<' ';
    }
}