#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
#define F0(i, n) for (int i = 0; i < (int)(n); i++)
char a[3010], b[3010];
int lena, lenb;
struct trie {
    string *v = NULL;
    trie *go[26];
    trie(){
        memset(go, 0, sizeof(go));
    }
} root, nil;
int main(){
    scanf("%s\n", a);
    while (scanf("%s", a)) {
        if (strcmp(a, "END") == 0) break;
        scanf("%s\n", b); lenb = strlen(b);
        trie *now = &root;
        F0(i, lenb){
            if (!now->go[b[i] - 'a'])
                now->go[b[i] - 'a'] = new trie();
            now = now->go[b[i] - 'a'];
        }
        now->v = new string();
        *now->v = a;
    }
    scanf("%s\n", a);
    char c;
    trie *now = &root; lena = 0;
    while (1) {
        c = getchar();
        if (c == 'E') break;
        if (c <= 'z' && c >= 'a') {
            a[lena++] = c;
            if (now->go[c - 'a']) now = now->go[c - 'a']; else now = &nil;
        } else {
            if (now->v)
                cout << *now->v;//printf("%s", now->v->c_str());
            else {
                a[lena] = '\0';
                printf("%s", a);
            }
            now = &root;
            lena = 0;
            printf("%c", c);
        }
    }
}