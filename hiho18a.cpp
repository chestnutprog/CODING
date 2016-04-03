#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define ti (b[i]-'a')
using namespace std;
char a[110],b[110];
vector<int> x[26];
int y[26];
vector<int> C;
int tmp[110],Ans,p;
void Merge_sort(int L,int R)
{
    if (L==R) return;
    int Mid=(L+R)>>1;
    Merge_sort(L,Mid);
    Merge_sort(Mid+1,R);
    int tl=L,tr=Mid+1,now=L;
    while (tl<=Mid&&tr<=R)
    {
        if (C[tl]<C[tr]) tmp[now++]=C[tl++];
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
int main(){
	scanf("%s%s",a,b);
	int t=strlen(a);
	for(int i=0;i<t;i++)x[a[i]-'a'].push_back(i+1);
	t=strlen(b);
	for(int i=0;i<t;i++){
		if(x[ti].size()>y[ti]){
			C.push_back(x[ti][y[ti]]);
			y[ti]++;
		}else{p++;}
	}
	Merge_sort(0,C.size());
	printf("%d",max(Ans-1+p,0));
}
