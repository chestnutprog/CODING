#include<bits/stdc++.h>
using namespace std;
int prime[110001],primesize;
bool isprime[110001];
void getlist(int listsize)
{
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i])prime[++primesize]=i;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++)
         {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)break;
        }
    }
}
int n;
int main(){
    ios::sync_with_stdio(0);
    getlist(100010);
    cin>>n;
    cout<<(n>=3?2:1)<<endl;
    for(int i=1;i<=n;i++)cout<<(isprime[i+1]^1)+1<<' ';
}