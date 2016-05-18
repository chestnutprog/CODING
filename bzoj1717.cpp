#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
typedef long long LL;
const int maxn=300000;
const int maxm=160000;
struct State {
    State *par;
    map<int,State*> go;
    int val; // max，当前状态能接收的串的最长长度
    int mi; // min，当前状态能接受的串的最短长度，即 par->val+1
    int right; // right集，表示当前状态可以在多少个位置上出现
    void init(int _val = 0){
        par = 0;
        val = _val;
        mi=0;
        right=0;
    }
    int calc(){ // 表示该状态能表示多少中不同的串
        if (par==0) return 0;
        return val-par->val;
    }
};
State *root, *last, *cur;
State nodePool[maxn];
State* newState(int val = 0) {
    cur->init(val);
    return cur++;
}
void initSAM() {
    cur = nodePool;
    root = newState();
    last = root;
}
void extend(int w) {
    State* p = last;
    State* np = newState(p->val + 1);
    np->right=1;
    while (p && p->go[w] == 0) {
        p->go[w] = np;
        p = p->par;
    }
    if (p == 0) np->par = root;
    else {
        State* q = p->go[w];
        if (p->val + 1 == q->val) np->par = q;
        else {
            State* nq = newState(p->val + 1);
            nq->go  = q->go;
            nq->par = q->par;
            np->par = q->par = nq;
            while (p && p->go[w] == q) {
                p->go[w] = nq;
                p = p->par;
            }
        }
    }
    last = np;
}

int d[maxm];
State* b[maxn];
void topo(){
    int cnt=cur-nodePool;
    int maxVal=0;
    memset(d,0,sizeof(d));
    for (int i=1;i<cnt;i++) maxVal=max(maxVal,nodePool[i].val),d[nodePool[i].val]++;
    for (int i=1;i<=maxVal;i++) d[i]+=d[i-1];
    for (int i=1;i<cnt;i++) b[d[nodePool[i].val]--]=&nodePool[i];
    b[0]=root;
}
int n,k,t,ans;
void gaoSamInit(){
    State* p;
    int cnt=cur-nodePool;
    for (int i=cnt-1;i>0;i--){
        p=b[i];
        p->par->right+=p->right;
        p->mi=p->par->val+1;
        if(p->right>=k)ans=max(ans,p->val);
    }
    printf("%d",ans);
}
int main(){
	scanf("%d%d",&n,&k);
	initSAM();
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		extend(t);
	}
	topo();
	gaoSamInit();
}
