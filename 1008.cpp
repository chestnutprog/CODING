#include<cstdio>
#include<cmath>
int n,k,x[20],ans;
int prime(long long x){
	long long s=sqrt(x);
	for(long long i =2 ;i<=s+1;i++)if(x%i==0)return 0;
	return 1;
}
int dfs(int xx,int y,long long z){
	if(xx)
	for(int i=y+1;i<=n;i++)
			dfs(xx-1,i,z+x[i]);
	else{
	if(prime(z))ans++;
	printf("%d %d %d\n",xx,y,z);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	dfs(k,0,0);
	printf("%d",ans);
}
	
