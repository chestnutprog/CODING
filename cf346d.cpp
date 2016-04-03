#include<cstdio>
#include<algorithm>
int n,a,b,c,d,x,ans,p;
int direct(){
	if(a==c){
		return (b>d)*2+1;
	}
	if(b==d){
		return (a>c)*2;
	} 
	return -1;
}
int strs(){
	if((x==0&&direct()==3)||(direct()==0&&x==3)){
		return direct()>x;
	}
	return direct()<x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		x=direct();c=a,d=b;
		scanf("%d%d",&a,&b);
		if(i>1){
		
			if(i>2){if(strs()==0){//if(strs()!=p){
				ans++;
			}
			p=strs();}
		}
		
	}
	printf("%d",ans);
}
