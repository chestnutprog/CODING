#include<cstdio>
int k,n,now,ans;
int t[509][509];
int main(){
	scanf("%d%d",&n,&k);
	now=n*n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=k;j--){
			t[i][j]=now--;
			if(j==k)ans+=now+1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=k-1;j>=1;j--){
			t[i][j]=now--;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)printf("%d ",t[i][j]);
		printf("\n");
	}
}
