#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
int n,k,ma;
char s[100010];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=0;i<n;i++)ma+=max(s[i]-'a','z'-s[i]);
	if(ma<k){printf("-1");return 0;}
	for(int i=0;i<n;i++){
		if(k>=max(s[i]-'a','z'-s[i])){
			printf("%c",s[i]-'a'>'z'-s[i]?'a':'z');
			k-=max(s[i]-'a','z'-s[i]);continue;
		}
		if(k>0){if(s[i]-'a'>=k)printf("%c",s[i]-k),k=0;else printf("%c",s[i]+k),k=0;continue;}
		printf("%c",s[i]);
	}
	
}
