#include<cstdio>
#include<cstring>
int A[27],B[27],C[27],T,a,b,c;
bool check(int x,int y){
	for(int i=0;i<27;i++)
	if(A[i]*x+B[i]*y!=C[i])return 0;
	printf("%d %d\n",x,y);
	return 1;
}
int main(){
	scanf("%d\n",&T);
	while(T--){
		scanf("%d%d%d\n",&a,&b,&c);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		char t;int ti;
		for(int i=1;i<=a;i++){
			scanf("%c%d\n",&t,&ti);
			A[t-'A']=ti;
		}
		for(int i=1;i<=b;i++){
			scanf("%c%d\n",&t,&ti);
			B[t-'A']=ti;
		}
		for(int i=1;i<=c;i++){
			scanf("%c%d\n",&t,&ti);
			C[t-'A']=ti;
		}
		int i,j;
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
				if(check(i,j))i=103,j=103;
		if(i!=104&&j!=104)printf("NO\n");
	}
}
