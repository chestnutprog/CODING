#include<bits/stdc++.h>
using namespace std;
int N=4000;
int Amin=1;
int Amax=5000;
int Bmin=1;
int Bmax=5000;
int Cmin=5;
int Cmax=100000;
int a,b,c;
int main(){
    ios::sync_with_stdio(0);
    srand(time(0));
    cout<<N<<endl;
    for(int i=1;i<=N;i++){
        do{
        a=rand()%(Amax-Amin)+Amin;
    }while(Bmax-max(Bmin,a+1)==0);
        b=rand()%(Bmax-max(Bmin,a+1))+max(Bmin,a+1);
        c=rand()%(Cmax-Cmin)+Cmin;
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
}