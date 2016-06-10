#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
int k,n;
bool c[502][502];
int q[502][502];
int p[502][502][2];
char t;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int main(){
    ios::sync_with_stdio(0);
    //scanf("%d%d",&k,&n);
    cin>>k>>n;
    F1(i,k)
      F1(j,k)
        {cin>>t;c[i][j]=t=='X';p[i][j][0]==!c[i][j];}
    F1(i,k)
      F1(j,k){
        q[i][j]=q[i][j-1]+q[i-1][j]-q[i-1][j-1]+c[i][j];
      }
      int temp;
    F1(i,k)
      F1(j,k){
        if(i>n&&j>n) temp  = q[i+n][j+n]-q[i][j+n]-q[i-n][j]+q[i][j];else temp = 0;
        if((!c[i-1][j])||(!c[i][j-1]))p[i][j][0] = p[i][j-1][0]+p[i-1][j][0]-p[i-1][j-1][0];
        p[i][j][1]=max(p[i-n][j-n][0]+temp,p[i][j-1][1]+p[i-1][j][1]-p[i-1][j-1][1]);
      }
      cout<<p[k][k][1];
}
