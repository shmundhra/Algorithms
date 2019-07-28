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

    for ( i = 1 ; i <= min( m ,sum ) ; i++)
        a[i] = 1;

    for ( i = m+1 ; i <= sum ; i++)
        a[i] = 0 ;


    for ( i = 1 ; i < n ; i++)
    {
        for ( j = sum ; j > 0 ; j--)
        {
            a[j] = 0 ;

            for ( k = j-1 ; k >= max ( 0 , j-m ) ; k-- )
                {
                    a[j] += a[k];
                }
        }
    }
    cout<<"\n"<<a[sum]<<endl;

}
