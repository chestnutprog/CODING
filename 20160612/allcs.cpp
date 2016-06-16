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
class BigInt {
public:
	BigInt();
	BigInt( long );
	BigInt( const BigInt & );
	BigInt operator+( const BigInt & ) const;
	const BigInt & operator+=( const BigInt & );
	const BigInt & operator=( const BigInt & );
	void print( ostream & ) const;
private:
	bool known;
	vector<short> digit;
};
ostream & operator<<( ostream &, const BigInt & );
BigInt::BigInt() : known( false ) {
}
BigInt::BigInt( long n ) {
	if( n<0 )
		known = false;
	else {
		known = true;
		while( n>0 ) {
			digit.push_back( n%10 );
			n /= 10;
		}
	}
}
BigInt::BigInt( const BigInt & bigint ) : known( bigint.known ) {
	if( known )
		for( short i=0; i<bigint.digit.size(); i++ )
			digit.push_back( bigint.digit[i] );
}
BigInt
BigInt::operator+( const BigInt & right ) const {
	BigInt result( *this );
	result += right;
	return result;
}
const BigInt &
BigInt::operator += ( const BigInt & right ) {
	if( ! right.known ) {
		known = false;
		digit.resize( 0 );
	}
	else if( known ) {
		short both;
		if( digit.size() <= right.digit.size() )
			both = digit.size();
		else
			both = right.digit.size();
		short carry( 0 );
		short i;
		for( i=0; i<both; ++i ) {
			short val = digit[i] + right.digit[i] + carry;
			digit[i] = val % 10;
			carry = val / 10;
		}
		for( ; i<digit.size(); ++i ) {
			short val = digit[i] + carry;
			digit[i] = val % 10;
			carry = val / 10;
		}
		for( ; i<right.digit.size(); ++i ) {
			short val = right.digit[i] + carry;
			digit.push_back( val % 10 );
			carry = val / 10;
		}
		if( carry > 0 )
			digit.push_back( carry );
	}
	return *this;
}
const BigInt &
BigInt::operator=( const BigInt & rhs ) {
	if( this != &rhs ) {
		known = rhs.known;
		digit.resize( 0 );
		if( known )
			for( short i=0; i<rhs.digit.size(); ++i )
				digit.push_back( rhs.digit[i] );
	}
	return *this;
}
void
BigInt::print( ostream & outf ) const {
	if( ! known )
		outf << "#UNK";
	else if( digit.size() == 0 )
		outf << 0;
	else
		for( short i=digit.size()-1; i>=0; --i )
			outf << digit[i];
}
ostream &
operator<<( ostream & outf, const BigInt & bigint ) {
	bigint.print( outf );
	return outf;
}
int n,m;
char a[3020],b[3020];
struct twobtrie{
    BigInt n;
    int in,out,inp;
    map<int,twobtrie*> go;
    twobtrie(){n=0;in=0;out=0;inp=0;}
};
vector<twobtrie*> importnode;
queue<twobtrie*> q;
vector<int> cc[58];
int num[58];
char now[3030];
int aaaa;
int tot;
void dfs(twobtrie* x){
    printf("%s\n",now);
    for(map<int,twobtrie*>::iterator y = x->go.begin(); y!= x->go.end();y++){
        now[tot++]=y->first+'A';
        dfs(y->second);
    }
    now[--tot]='\0';
}
int main(){
	//freopen("allcs.in","r",stdin);
	//freopen("allcs.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    scanf("%s",b+1);
    scanf("%d",&aaaa);
    F1(i,m)cc[b[i]-'A'].push_back(i);
    importnode.resize(m+10);
		F0(i,m+2)importnode[i]=NULL;
    importnode[0]=new twobtrie();
    F0(i,n){
      int size = cc[a[i]-'A'].size();
      if(size>=(++num[a[i]-'A'])){
        int j = cc[a[i]-'A'][num[a[i]-'A']-1];
        if(!importnode[j])importnode[j]=new twobtrie();
        F0(k,j){
          if(importnode[k]&&!importnode[k]->go.count(b[j]-'A'))
          {
              importnode[k]->out=1;importnode[j]->in=1;importnode[j]->inp++;
		          importnode[k]->go[b[j]-'A']=importnode[j];
          }
        }
      }
    }
    twobtrie *root = importnode[0];
    if(aaaa)dfs(root);
    F0(j,m+2)
      if(importnode[j]&&!importnode[j]->in)
	  q.push(importnode[j]),importnode[j]->n=1;
    while(!q.empty()){
        twobtrie* x = q.front();q.pop();
        if(x->in)x->n=x->n+1;
        for(map<int,twobtrie*>::iterator y = x->go.begin(); y!= x->go.end();y++){
            y->second->n+=x->n;
            y->second->inp--;
            if(!y->second->inp)q.push(y->second);
        }
    }
    BigInt ans = 0;
    F0(j,m+2)if(importnode[j]&&importnode[j]->in&&!importnode[j]->out) ans+=importnode[j]->n;
    cout<<ans<<endl;
}
