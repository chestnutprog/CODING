#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=100000+19;
int n,C[Maxn],tmp[Maxn],Ans;
inline void Merge_sort(int L,int R)
{
    if (L==R) return;
    int Mid=(L+R)>>1;
    Merge_sort(L,Mid);
    Merge_sort(Mid+1,R);
    int tl=L,tr=Mid+1,now=L;
    while (tl<=Mid&&tr<=R)
    {
        if (C[tl]<=C[tr]) tmp[now++]=C[tl++];
            else
            {
                tmp[now++]=C[tr++];
                Ans+=Mid-tl+1;
            }
    }
    while (tl<=Mid) tmp[now++]=C[tl++];
    while (tr<=R) tmp[now++]=C[tr++];
    for (int i=L;i<=R;i++) C[i]=tmp[i];
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&C[i]);
    Merge_sort(0,n-1);
    printf("%d\n",Ans);
}
