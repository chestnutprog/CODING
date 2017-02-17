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
#define ud(a,b) ((a/b)+((a%b)&1))
#define mod 1000000007
#define once (((p<x1&&x1<x2)&&d==1)||((p>x1&&x1>x2)&&d==-1))
#define toto (((p<x1)&&d==1)||((p>x1)&&d==-1))
#define gogo (((x1<x2)&&d==1)||((x1>x2)&&d==-1))
using namespace std;
int s,x1,x2,t1,t2,p,d;
string x;
int ans=0x7fffffff;
int shangche,zuoche;
int main()
{
    ios::sync_with_stdio(0);
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    d=(d==1);
    ans=min(ans,abs(x2-x1)*t2);
//    if(once){
//        if(d==1){
//            ans=min(ans,x2-p);
//        }else{
//            ans=min(ans,p-x2);
//        }
//    }else{
        if(d==1){
            if(p<=x1){
                shangche=x1-p;
            }else{
                shangche=s-p+s-x1;d^=1;
            }
        }else{
            if(p<x1){
                shangche=p+x1;d^=1;
            }else{
                shangche=p-x1;
            }
        }
        if(d==1){
            if(x1<x2){
                zuoche=x2-x1;
            }else{
                zuoche=s-x1+s-x2;d^=1;
            }
        }else{
            if(x1<x2){
                zuoche=x1+x2;d^=1;
            }else{
                zuoche=x1-x2;
            }
        }
ans=min(ans,(shangche+zuoche)*t1);
//    }
    cout<<ans;
	return 0;
}

