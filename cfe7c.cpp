#include<cstdio>
int n,m,p[200010],next[200010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=n;i>=1;i--)if(p[i+1]!=p[i])next[i]=i+1;else next[i]=next[i+1];
	int l,r,x;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&x);
		if(p[l]!=x){
			printf("%d\n",l);
		}else{
			if(next[l]<=r) printf("%d\n",next[l]);else printf("-1\n");
		}
	}
}
