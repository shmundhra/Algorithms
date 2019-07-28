#include<iostream>
using namespace std ;

int left ( int[] , int  , int  , int ) ;

int right ( int arr[] , int i , int n , int max )
{
    int j ;

    for ( j = i ; j < n ; j++ )
    {
        if ( arr[j] > arr[j-1] )
        {
                if ( arr[j] > max )
                    return 0 ;
        }
        else
        {
            if ( arr[j] < arr[j-2] )
                return 0 ;

            else
                return left ( arr , j+1 , n , arr[j-2] ) ;

        }
        return 1 ;
    }
}



int left ( int arr[] , int i , int n , int min )
{
    int j ;

    for ( j = i ; j < n ; j++ )
    {
        if ( arr[j] < arr[j-1] )
        {
                if ( arr[j] < min )
                    return 0 ;
        }
        else
        {
            if ( arr[j] > arr[j-2] )
                return 0 ;

            else
                return right ( arr , j+1 , n , arr[j-2] ) ;

        }
        return 1 ;
    }
}


int main ()
{
    int i , n , a[1000] , val ;
    cin>>n;

    for  ( i = 0 ; i < n ; i ++)
        cin>>a[i];

    if ( a[1] > a[0] )
        val = right ( a , 2 , n , 9999) ;

    else
        val = left ( a , 2 , n , -9999) ;

    if ( val ) cout <<"Possible" ;
    else       cout <<"Not Possible" ;

}
