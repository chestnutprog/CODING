#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
int num;int node[100010];int ans[100010];
void pushup(int x){
	int j = x , i = j/2;node[0]=node[j];
    while ( j > 0)if(node[i]<=node[0])break;else node[j]=node[i],j=i,i=i/2;
	node[j]=node[0];
}
void pushdown(int x){
	int i = 1, j = 2;node[0]=node[i];
    while (j <= x) {
    	if (j < x && node[j] > node[j + 1])j++;
        if (node[0] <= node[j]) break;node[i]= node[j];i = j; j = i * 2;}
    node[i]=node[0];
}
void pop(){node[1]=node[num--];pushdown(num);}
void push(int x){node[++num]=x;pushup(num);}
bool endss;int tot;
char s[100];int t;
int main(){
    while(scanf("%s",s)!=EOF)
    	if(s[0]=='E')ans[++tot]=node[1],pop();//printf("%d ",node[1]),pop();
    	else{
    		if(s[strlen(s)-1]=='.')s[strlen(s)-1]='\0';
    		sscanf(s,"%d",&t);
    		push(t);
    	}
    F1(i,tot-1)printf("%d ",ans[i]); printf("%d",ans[tot]);
}
