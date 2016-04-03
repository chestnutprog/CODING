#include<cstdio>
#include<cstring>
char s[300010];
int p[300010][4],n;
long long ans;
int main(){
	scanf("%s",s);
	n=strlen(s);
	p[0][(s[0]-'0')%4]++;
	ans+=p[0][0];
	int now;
	for(int i=1;i<n;i++){
		now = s[i]-'0';
		p[i][(now)%4]+=p[i-1][0]+1;
		p[i][(now+10)%4]+=p[i-1][1];
		p[i][(now+20)%4]+=p[i-1][2];
		p[i][(now+30)%4]+=p[i-1][3];
		ans+=p[i][0];
	}
	printf("%I64d",ans);
}
