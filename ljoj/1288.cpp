

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int x[5000 + 2] , y[5000 + 2];
int f[3][5000 + 2];
int len;

int main()
{
  scanf("%d",&len);
 for(int i=1;i<=len;i++)scanf( "%d" , &x[i] );
 for( register int i = 1 ; i <= len ; i++ ) y[i] = x[ len - i + 1 ];
 for( register int i = 1 ; i <= len ; i++ )
  for( register int j = 1 ; j <= len ; j++ )
   if( x[i] == y[j] ) f[i&1][j] = f[(i&1)^1][j - 1] + 1;
   else f[i&1][j] = max( f[(i&1)^1][j] , f[i&1][j - 1] );
 cout << len - f[len&1][len] << endl;
 return 0;
}
