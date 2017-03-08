#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;


#define se second
#define fi first
#define pb push_back
#define mp make_pair


string str[500010];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
    	cin>>str[i];
    }
    int idx = n-2;
    while(idx >=0) {
    	bool flag = true;
    	for(int i = 0; i < min(str[idx].size(), str[idx+1].size()); i++) {
    		if(str[idx][i] < str[idx+1][i]) {
    			flag = false;
    			break;
    		} else if(str[idx][i] > str[idx+1][i]) {
    			flag = true;
    			str[idx].resize(i);
    			break;
    		}
    	}
    	if(flag) {
    		str[idx].resize(str[idx+1].size());
    	}
    	idx--;
    }
    for(int i = 0; i < n; i++) {
    	cout<<str[i]<<'.'<<endl;
    }
}


void union(int x,int y){
    if(getfa(x)!=)
}

