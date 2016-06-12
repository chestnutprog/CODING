#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
char s[3020];
int main(){
	freopen("allcs.in","w",stdout);
	printf("3004 3004\n");
	F0(i,3004){
		s[i]=rand()%2?rand()%26+'A':rand()%26+'a';
	}
	printf("%s\n%s\n",s,s);
	printf("0");
}
