#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#define inf 1000000000
#define maxn 500+100
#define maxm 500+100
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define mod 1000000007
using namespace std;
int a,b,c;
deque<char> deq;
string x;
int pos=1;
int main()
{
    ios::sync_with_stdio(0);
    cin>>a;
    cin>>x;
    if(a&1)deq.push_back(x[0]);
    for(int i=a&1;i<a;i++,pos^=1){
        if(!pos){
            deq.push_back(x[i]);
        }else{
            deq.push_front(x[i]);
        }
    }
    for(deque<char>::iterator i=deq.begin();i!=deq.end();i++)cout<<*i;
	return 0;
}

