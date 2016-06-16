#include<iostream>
int a[1100][1100],F[1100][1100],jilu[1100];
using namespace std;
int main()
{
    int f,v;
    cin>>f>>v;
    for(int i=1; i<=f; i++)
        for(int j=1; j<=v; j++)cin>>a[i][j];
    for(int i=1; i<=f; i++)
        for(int j=0; j<=v; j++)
            if (i>j) F[i][j]=-1000000;
    for(int i=1; i<=f; i++)
        for(int j=1; j<=v; j++)
            F[i][j] = max( F[i][j-1], F[i-1][j-1]+a[i][j] );
    int teml=v;
    for(int i=f; i>=1; i--)
    {
        int temp=-99999999;
        for(int j=teml; j>=1; j--)
        {
            if(F[i][j]>=temp)
            {
                temp=F[i][j];
                teml=j-1;
            }
        }
        jilu[i]=teml+1;
    }
    cout<<F[f][v]<<endl;
    for(int i=1; i<=f; i++)cout<<jilu[i]<<' ';
}
