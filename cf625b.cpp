#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<int> q;
int ans,na,nb;
char a[100010],b[100010];
int nextt[100010];
int main(){
	scanf("%s%s",a+1,b+1);
	na=strlen(a+1);
	nb=strlen(b+1);
	int j=0;
	for(int i=2;i<=nb;i++)
	{
		while(j>0&&b[j+1]!=b[i])j=nextt[j];
		if(b[j+1]==b[i])j++;
		nextt[i]=j;
	}
	j=0;
	for(int i=1;i<=na;i++)
	{
		while(j>0&&b[j+1]!=a[i])j=nextt[j];
		if(b[j+1]==a[i])j++;
		if(j==nb)q.push(i-nb),j=nextt[j];
	}
	int t=-10000000;
	while(!q.empty()){
		if(t+nb>q.front())q.pop();
		else ans++,t=q.front();
	}
	cout<<ans;
}
