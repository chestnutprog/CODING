#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int p[]={1,2,3,4,5,6,7,8,9,10};
int main(){
    int ans=0;
    do{
        int t=0;
        F1(i,sizeof(p)/sizeof(int)-1){
            //printf("%d ",p[i]);
            int mins=0x7fffffff,maxs=0;
            F0(j,i)maxs=max(maxs,p[j]);
            F(j,i,sizeof(p)/sizeof(int)-1)mins=min(mins,p[j]);
            if(maxs<mins){t=1;break;}
        }
        if(!t)ans++;
        //if(p[0]>p[sizeof(p)/sizeof(int)-1])ans++;
        //printf("\n");
    }while(next_permutation(p,p+(sizeof(p)/sizeof(int))));
    printf("%d",ans);
}
