#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int n,m,rd[100010],tot,t[100010],he[100010],next[100010];
int ans;
queue<int> head;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&y,&x);
		rd[x]++;
		t[++tot]=x;next[tot]=he[y];he[y]=tot;
	}
	for(int i=1;i<=n;i++)
		if(rd[i]==0){head.push(i);ans++;}
	while(!head.empty()){
		int q=head.front();head.pop();
		for(int x=he[q],i=t[x];i!=0&&x!=0;x=next[x],i=t[x]){
			rd[i]--;
			if(rd[i]==0)head.push(i),ans++;
			}
	} 
	if(ans==n){printf("o(กษ_กษ)o");return 0;}
	printf("T_T\n%d",n-ans);
}
