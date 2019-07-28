#include<iostream>

using namespace std ;

int max ( int a , int b )
{
    return a>b ? a : b ;
}

int min ( int a , int b )
{
    return a<b ? a : b ;
}


int main ()
{
    int i , j , k ;
    int n , m , sum ;
    cin>>n;
    cin>>m;
    cin>>sum;

    int a[sum+1] , b[sum+1];
    a[0] = 0 ;
    b[0] = 0 ;

    for ( i = 1 ; i <= min( m ,sum ) ; i++)
        a[i] = 1;

    for ( i = m+1 ; i <= sum ; i++)
        a[i] = 0 ;


    for ( i = 1 ; i < n ; i++)
    {
        for ( j = 1 ; j <= min(m,sum) ; j++ )
            b[j] = b[j-1] + a[j-1] ;

        for ( j = m+1 ; j <= sum ; j++ )
            b[j] = b[j-1] + a[j-1] - a[j-(m+1)] ;

        for ( k = 0 ; k <= sum ; k++)
        a[k] = b[k] ;

    }
    cout<<"\n"<<a[sum]<<endl;

}
