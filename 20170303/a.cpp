#include <bits/stdc++.h>
using namespace std;
#define mid ((l + r) >> 1)
int n, a[200002], sum[200002];
double median(int l, int r){
    if ((r - l) & 1)
        return (a[mid] + a[mid] + 1) / 2.0;
    else
        return a[mid];
}
double ans = 0;
int main(){
    //ios::sync_with_stdio(0);
    //cin >> n;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&n);
    int delta=0x7fffffff;
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);//cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i]=sum[i-1]+a[i];
    for (int i = 1; i < n; i++) {
        if(a[i + 1] - a[i] < delta){
            delta = a[i+1] - a[i];
            ans=max(ans,(((a[i]+a[i+1]+a[n])/3.0)-a[i+1]));
        }
    }
    for(int i=1;i<n/2;i++){
        double sums=sum[n]-sum[n-i]+sum[i]+a[i+1];
        ans=max(ans,sums/(i<<1|1)-a[i+1]);
    }
    for(int i=1;i<n/2;i++){
        double sums=sum[n]-sum[n-i-1]+sum[i];
        ans=max(ans,sums/(i<<1|1)-a[n-i]);
    }
    /*
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int i = 1, j = n;
    while (j > i) {
        if (abs(((sum[j - 1] - sum[i - 1]) * 1.0 / (j - i)) - median(i, j - 1)) >
            abs(((sum[j] - sum[i - 2]) * 1.0 / (j - i)) - median(i + 1 , j)) ) {
                j--;
        }else{
            i--;
        }
    }*/
    if(n>2)printf("%.4f",ans);
    else printf("0.0000");

}