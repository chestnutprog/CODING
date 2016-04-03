#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXNODE 100100
char s[50100];
struct samnode {
    samnode *par, *ch[26];
    int val;
    samnode() {
        par = 0; memset(ch, 0, sizeof(ch));
        val = 0;
    }
} node[MAXNODE], *root, *last;
int size = 0;
inline void init() {
    last = root = &node[0];
}
inline void add(int c) {
    samnode *p = last;
    samnode *np = &node[++size]; np->val = p->val + 1;
    while (p && !p->ch[c])
        p->ch[c] = np, p = p->par;
    if (!p) np->par = root;
    else {
        samnode *q = p->ch[c];
        if (q->val == p->val + 1)
            np->par = q;
        else {
            samnode *nq = &node[++size]; nq->val = p->val + 1;
            memcpy(nq->ch, q->ch, sizeof(q->ch));
            nq->par = q->par;
            q->par = np->par = nq;
            while (p && p->ch[c] == q)
                p->ch[c] = nq, p = p->par;
        }
    } last = np;
}
int main(){
	init();
	scanf("%s",s);
	int n=strlen(s),ans=0;
	for(int i=0;i<n;i++) add(s[i]-'A');
	for(int i=1;i<=size;i++) ans+=node[i].val-node[i].par->val;
	printf("%d\n",ans);
	return 0;
}
