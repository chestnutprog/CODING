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
int n,a[5][5];
vector<int> v;
char t;
bool ans;
int main()
{
    ios::sync_with_stdio(0);
    for1(i,4)
        for1(j,4){
            cin>>t;
            switch (t) {
                case 'x':
                a[i][j]=1;
                break;
                case 'o':
                a[i][j]=-10;
                break;
                case '.':
                a[i][j]=0;
                break;
            }
        }
    for1(i,4)
        for1(j,4){
            if(i>1&&i<4){
                ans|=(a[i][j]+a[i-1][j]+a[i+1][j])>=2;
            }
            if(j>1&&j<4){
                ans|=(a[i][j]+a[i][j-1]+a[i][j+1])>=2;
            }
            if(i>1&&i<4&&j>1&&j<4){
                ans|=(a[i][j]+a[i-1][j-1]+a[i+1][j+1])>=2;
                ans|=(a[i][j]+a[i+1][j-1]+a[i-1][j+1])>=2;
            }
        }
        cout<<(ans?"YES":"NO");
}

