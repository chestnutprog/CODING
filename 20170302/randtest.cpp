#include<bits/stdc++.h>
using namespace std;
int counts[50];
int main(){
    ios::sync_with_stdio(0);
    srand(time(0));
    for(int i=1;i<=1000;i++)counts[rand()%13+1]++;
    for(int i=1;i<=13;i++)cout<<i<<':'<<counts[i]<<endl;
}