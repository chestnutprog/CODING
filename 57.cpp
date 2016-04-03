#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAX 200010
using namespace std;
int a[MAX];
struct tree{
    int l,r;
    vector<int> sum;
}f[MAX*4];
void pushup(int i){
	vector<int> tmp;
	tmp.resize(f[i<<2|1].sum.size()+f[i<<2].sum.size());
	vector<int>::iterator it = set_union(f[i<<2|1].sum.begin(),f[i<<2|1].sum.end(),f[i<<2].sum.begin(),f[i<<2].sum.end(),tmp.begin());
	tmp.resize(it-tmp.begin());
	f[i].sum.resize(tmp.size());
    f[i].sum=tmp;
}
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].sum.push_back(a[left]);
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
vector<int> query(int i,int left, int right) {
        int mid=(f[i].l+f[i].r)/2;
        if(f[i].l==left&&f[i].r==right) return f[i].sum;
        if(mid>=right) return query(i*2,left,right);
        if(mid<left) return query(i*2+1,left,right);
        vector<int> a=query(i*2,left,mid);
        vector<int> b=query(i*2+1,mid+1,right);
    	vector<int> tmp;
    	tmp.resize(a.size()+b.size());
		vector<int>::iterator it = set_union(a.begin(),a.end(),b.begin(),b.end(),tmp.begin());
		tmp.resize(it-tmp.begin());
        return tmp;
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int a,b;
        scanf("%d%d",&a,&b);
		printf("%d\n",query(1,a,b).size());
    }
    return 0;
}
