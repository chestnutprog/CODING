#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int n;
char line[30];
pair<int,int> readc(int x){int y=0,j=x;while(line[++j]<='Z'&&line[j]>='A')y=y*26+line[j]-'A'+1;return make_pair(y,j-1);}
pair<int,int> readn(int x){int y=0,j=x;while(line[++j]<='9'&&line[j]>='0')y=y*10+line[j]-'0';return make_pair(y,j-1);}
void printc(int y,int x){
stack<char> cha;
while(x>=0)cha.push(x%26+'A'),x/=26,x--;
while(!cha.empty())printf("%c",cha.top()),cha.pop();
printf("%d",y);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",line);
		pair<int,int> j;
		if((j=readc(-1)).first==18){
			j=readn(j.second);
			int x=j.first;
			if((j=readc(j.second)).first!=0){
				j=readn(j.second);
				printc(x,j.first-1);
				printf("\n");
			}else{
				printf("R%dC%d\n",x,18);
			} 
		}else{
			printf("R%dC%d\n",readn(readc(-1).second).first,readc(-1).first);
		}
	}
} 
