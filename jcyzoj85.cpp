#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define drep(i,r,l) for(int i=r;i>=l;--i)
 
inline int read(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
 
int col[1000100];
int num[2222];
 
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n=read(),m=read();
	rep(i,1,n) col[i]=read();
	int cnt=0,a=1,b=0;
	while(cnt<m){
		b++;
		num[col[b]]++;
		if(num[col[b]]==1) cnt++;
		while(num[col[a]]>1) num[col[a]]--,a++;
	}
	int ansa=a,ansb=b;
	while(b<=n){
		b++;
		num[col[b]]++;
		while(num[col[a]]>1) num[col[a]]--,a++;
		if(b-a<ansb-ansa) ansa=a,ansb=b;
	}
	printf("%d %d\n",ansa,ansb);
} 
