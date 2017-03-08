#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cp;
#define maxn 262145
#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)
cp a[maxn],b[maxn];
int n,m,L,R[maxn],ans[maxn];
const double pi = acos(-1);
void fft(cp a[],int flag){
    F0(i,n)if(i<R[i])swap(a[i],a[R[i]]);
    for(int i=1;i<n;i<<=1){
        cp wn(cos(pi/i),sin(flag*pi/i)),x,y;
        for(int j=0;j<n;j+=i<<1){
            cp w(1,0);
            for(int k=0;k<i;k++,w*=wn){
                x=a[j+k];
                y=w*a[j+i+k];
                a[j+k]=x+y;
                a[j+i+k]=x-y;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    F0(i,n+1)cin>>a[i];
    F0(i,m+1)cin>>b[i];
    m+=n;
    for(n=1;n<=m;n<<=1)L++;
    F0(i,n)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
    fft(a,1);fft(b,1);
    F0(i,n+1)a[i]*=b[i];
    fft(a,-1);
    F0(i,m+1)cout<<int(a[i].real()/n+0.5)<<' ';
}