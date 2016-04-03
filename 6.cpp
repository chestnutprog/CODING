#include<cstdio>
using namespace std;
int n,ks;
int map[105][105];
int ans[105][105]; 

inline void add(int x,int y,int val){
    if (1<=x && x<=n && 1<=y && y<=n) ans[x][y]+=val;
}

int main(){
    scanf("%d%d",&n,&ks);
    for (int i=1;i<=ks;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        map[x][y]++;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (map[i][j]){
                ans[i][j]+=map[i][j];
                for (int k=1;k<=n;k++){
                    add(i,j+k,map[i][j]);
                    add(i,j-k,map[i][j]);
                    add(i+k,j+k,map[i][j]);
                    add(i+k,j,map[i][j]);
                    add(i+k,j-k,map[i][j]);
                    add(i-k,j+k,map[i][j]);
                    add(i-k,j,map[i][j]);
                    add(i-k,j-k,map[i][j]);
                }
            }
        }
    }
    int Ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (ans[i][j]==ks) Ans++;
        }
    }
    printf("%d\n",Ans);
    return 0;
}
