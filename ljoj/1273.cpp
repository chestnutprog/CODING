#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define F(i, x, y) for (int i = x; i <= y; i++)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
#define INF 0x7fffffff
long long n,m,x1,y3,x2,y2;
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
BigInt dp[52][52];
int main(){
    scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&x1,&y3,&x2,&y2);
    F0(i,n+1)F0(j,m+1)dp[i][j]=0;
    dp[1][1]=1;
    F1(i,n)
    F1(j,m)
    {
      if((i<x1||i>x2)||(j<y3||j>y2))dp[i][j]+=dp[i-1][j];
      if((i<x1||i>x2)||(j<y3||j>y2))dp[i][j]+=dp[i][j-1];
    }
    cout<<dp[n][m];
}
