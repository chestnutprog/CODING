#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 2147483647;

int n,m,a[400];
int info[400][30];

int dp(int now,int x)
{
    if(info[now][x]>=0) return info[now][x];
    int &ans=info[now][x];
    ans = INF;
    if(x==1)
    {
        int k=0,mid = now + (n-now) / 2;
        for(int j=now;j<=n;j++)
            k += j <= mid ? a[mid]-a[j] : a[j]-a[mid];
        ans = k;
    }
    else
    for(int i=now;i<=n-x+1;i++)
    {
        int k=0,mid=now+(i-now)/2;
        for(int j=now;j<=i;j++)
            k += j <= mid ? a[mid]-a[j] : a[j]-a[mid];
        ans = min(dp(i+1,x-1) + k,ans);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(info,-1,sizeof(info));
    int ans=dp(1,m);
    printf("%d\n",ans);
    return 0;
}
