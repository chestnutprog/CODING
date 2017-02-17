#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;
#define F0(i, n) for (int i = 0; i < (int)(n); i++)
char a[20];
int lena;
struct trie {
    //trie *go[26];
    map<int,trie*> go;
    trie *fa;
    int sum;
    trie(){
    }

    trie(trie *f){
        fa = f;sum=0;
    }

    void pushup(){
        sum++;
        if (fa) fa->pushup();
    }
} root, nil;
int main(){
    while (cin.getline(a,20)) {
        lena = strlen(a);
        if (strcmp(a, "") == 0) break;
        trie *now = &root;
        F0(i, lena){
            if (now->go.count(a[i] - 'a')==0) now->go[a[i] - 'a'] = new trie(now);
            now = now->go[a[i] - 'a'];
        }
        now->pushup();
    }
    while (scanf("%s", a)!=EOF) {
        lena = strlen(a);
        trie *now = &root;
        F0(i, lena){
            if (now->go.count(a[i] - 'a')==0) now=&nil;else
            now = now->go[a[i] - 'a'];
        }
        printf("%d\n",now->sum);
    }
}