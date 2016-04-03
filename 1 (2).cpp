#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
struct point{
    int id,od,ard;
    int ccd=-1;
};
multimap<int,int> mp;
point po[100010];
int adc,ad[100010],a,b,n,m,ans;
int finds(int o){
    if(po[o].ard==po[o].id) return 1;
    if(po[o].ccd>0) return po[o].ccd;
    int q=0;
    typedef multimap<int, int>::iterator multiMapItor;
     pair<multiMapItor, multiMapItor> pos = mp.equal_range(o);
     while(pos.first != pos.second)
     {
         q+=finds(pos.first->second);
         ++pos.first;
     }
     return po[o].ccd=q;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        po[a].od++;po[b].id++;
        mp.insert(make_pair(b,a));
    }
    for(int i=1;i<=n;i++)if(po[i].od==0)ad[++adc]=i;
    for(int i=1;i<=adc;i++)ans=(ans+finds(ad[i]))%23333333;
    printf("%d",(int)ans%23333333);
    return 0;
}

