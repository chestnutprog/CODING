#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define For(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;

int N,Ans=0;
int bt=0,pt=1;
char ss[100000+5];
int dp[2][4][4][4][4];
int kn[100000+5];

int judge(int a,int b,int c){
	int r1 = 0,r2 = 0,r3 = 0;
	if(a == 1 || b == 1 || c == 1)r1 = 1;
	if(a == 2 || b == 2 || c == 2)r2 = 1;
	if(a == 3 || b == 3 || c == 3)r3 = 1;
	return (r1+r2+r3);
}

int main(){
	scanf("%d%s",&N,ss+1);
	for(int i = 1;i <= N;++ i){
		if(ss[i] == 'M')kn[i] = 1;
		else if(ss[i] == 'F')kn[i] = 2;
		else if(ss[i] == 'B')kn[i] = 3;
	}

	For(i,0,3)For(j,0,3)For(k,0,3)For(g,0,3)
	{	dp[0][i][j][k][g] = dp[1][i][j][k][g] = -1;}
	dp[0][0][0][0][0] = 0;

	For(i,1,N){
		int now = kn[i];
		For(a,0,3)For(b,0,3)For(c,0,3)For(d,0,3){
			if(dp[bt][a][b][c][d] < 0)continue;
			dp[pt][b][now][c][d] = max(dp[bt][a][b][c][d]+judge(a,b,now),dp[pt][b][now][c][d]);
			dp[pt][a][b][d][now] = max(dp[bt][a][b][c][d]+judge(c,d,now),dp[pt][a][b][d][now]);
			dp[bt][a][b][c][d] = -1;
		}
		bt ^= 1;pt ^= 1;
	}

	bt ^= 1;pt ^= 1;
	For(a,0,3)For(b,0,3)For(c,0,3)For(d,0,3){
		Ans = max(Ans,dp[pt][a][b][c][d]);
	}
	printf("%d\n",Ans);

	return 0;
}
