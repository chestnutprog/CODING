#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int dis[10001]={0},f[10001]={0},k[3][10001]={0};
	int l1,l2,l3,c1,c2,c3,n,a,b;
	const long MAX=1111111111;
	scanf("%d%d%d%d%d%d%d%d%d",&l1,&l2,&l3,&c1,&c2,&c3,&n,&a,&b);
	a--,b--;
	int i,temp;
	if(a>b)swap(a,b);
	k[0][a]=a,k[1][a]=a,k[2][a]=a;
	for(i=1;i<=n;i++) scanf("%d",&dis[i]);
	f[0]=MAX;
	f[a]=0;
	for(i=a+1;i<=b;i++){
		temp=-1;
		if(dis[i-1]+l1>=dis[i]){
			temp=k[0][i-1];
			while(dis[i]-dis[temp]>l1) temp++;
		}
		if(temp<i) k[0][i]=temp;
		temp=-1;
		if(dis[i-1]+l2>=dis[i]){
			temp=k[1][i-1];
			while(dis[i]-dis[temp]>l2) temp++;
		}
		if(temp<i) k[1][i]=temp;
		temp=-1;
		if(dis[i-1]+l3>=dis[i]){
			temp=k[2][i-1];
			while(dis[i]-dis[temp]>l3) temp++;
		}
		if(temp<i) k[2][i]=temp;
	}
	for(i=a+1;i<=b;i++){
		f[i]=MAX;
		if(k[0][i]!=-1&&(f[i]>f[k[0][i]]+c1||f[i]==0)) f[i]=f[k[0][i]]+c1;
		if(k[1][i]!=-1&&(f[i]>f[k[1][i]]+c2||f[i]==0)) f[i]=f[k[1][i]]+c2;
		if(k[2][i]!=-1&&(f[i]>f[k[2][i]]+c3||f[i]==0)) f[i]=f[k[2][i]]+c3;
	}
	printf("%d\n",f[b]);
	return 0;
}
