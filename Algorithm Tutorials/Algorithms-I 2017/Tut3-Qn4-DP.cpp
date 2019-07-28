#include<iostream>

using namespace std ;

int main()
{

    int i , j , n , a[1000] , g[1000] ;
    cin>>n;
    for ( i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }

    g[1] = a[0] ;

    for ( i = 1 , j = 1 ; i < n ; i++ )
    {
        if ( j%2 )
        {
            if ( a[i] > g[j] )
                g[++j] = a[i] ;
            else
                g[j] = a[i] ;
        }

        else
        {
            if ( a[i] < g[j] )
                g[++j] = a[i] ;
            else
                g[j] = a[i] ;
        }
    }
    cout<<endl;

    for ( i = 1 ; i <= j ; i++)
    cout<<g[i]<<" " ;

    cout<<endl;
}
