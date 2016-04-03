#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
bool flag[50010];
int f[50000][21][2];
struct edge {
	int i,o;
	bool operator<(const edge & b)const {
		return (this->i<b.i);
	}
};
map<edge,int> edges;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		int p1,p2,t;
		scanf("%d%d%d",&p1,&p2,&t);
		edge xx,yy;
		xx.i=p1;
		yy.o=p1;
		yy.i=p2;
		yy.o=p2;
		edges.insert(make_pair(xx,t));
		edges.insert(make_pair(yy,t));
	}
	flag[1]=1;
	for(int i=2; i<=n; i++)
		for(int j=k; j>=max(k-i+1,0); j--)
			for(int l=1; l<=n; l++)
				if(flag[l]) {
					edge a;
					a.i=i;
					a.o=l;
					if(edges.count(a)&&l!=i) {
						map<edge,int>::iterator it=edges.find(a);
						int th=it->second;
						if(f[i][j][0]!=0) {
							if(j!=k) {
								f[i][j][0]=min(min(f[l][j+1][1]+th,f[l][j][0]+th),f[i][j][0]);
								f[i][j][1]=min(min(f[l][j+1][1],f[l][j][0]),f[i][j][0]);
							} else {
								f[i][j][0]=min(f[l][j][0]+th,f[i][j][0]);
								f[i][j][1]=min(f[l][j][0],f[i][j][0]);
							}
						} else {
							if(j!=k) {
								f[i][j][0]=min(f[l][j+1][1]+th,f[l][j][0]+th);
								f[i][j][1]=min(f[l][j+1][1],f[l][j][0]);
							} else {
								f[i][j][0]=f[l][j][0]+th;
								f[i][j][1]=f[l][j][0];
							}

						}

						flag[i]=1;
					}
				}
	printf("%d",min(f[n][0][0],f[n][0][1]));
}


