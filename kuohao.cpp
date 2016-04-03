#include<set>
#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int fa[110],size[110];
int fat(int x){
	return fa[x]==x?x:fa[x]=fat(fa[x]);
}
int n,k,a,b,ans,ansb;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	//cin>>a;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
	for(int i=1;i<=k;i++){
		scanf("%d%d",&a,&b);
		if(fat(a)!=fat(b)){
		size[fat(b)]+=size[fat(a)];
		size[fat(a)]=0;
		fa[fat(a)]=fat(b);}
	}
	ans=n;
	for(int i=1;i<=n;i++)if(fa[i]!=i)ans--;
	else ansb=max(ansb,size[i]);
	printf("%d %d",ans,ansb);
} 
