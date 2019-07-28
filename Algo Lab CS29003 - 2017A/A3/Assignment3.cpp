/*
Name: Assignment3.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: July 27 , 2017
Description: We play a ball game and decide on optimum choices of number of balls to choose using Dynamic Programming .
*/

#include<iostream>
using namespace std ; 
#include<cstdlib>

extern int *registerme ( );
extern int makemove1 ( int );
extern int makemove2 ( int );


/*
Name - dptable
Input - n ( Number of Balls) , k ( Number of possible selections) , p( The selections of balls i can make)
Output - The Table table[0..n] containing the optimum index of the array p for that number of balls - i 
Description - In this function we are making a table for our DP Algorithm where each index stores the
              corresponding index of the array p such that a choice of p[i] balls is optimum at this stage 
              
*/

int* dptable(int n , int k , int p[] )
{
  int *table ;
  table = new int[n+1] ;

  int i , j , flag ; 

  for ( i = 0 ; i < p[0] ; i++ )
    table[i] = -1 ; 

  for ( i = p[0] ; i <= n ; i++)
  {
    for ( j = 0 , flag = 0 ; p[j] <= i ; j++)
    {
        if ( table[ i-p[j] ] == -1 )
        {
          flag = 1 ;
          table[i] = j ;
        }
    }

    if ( !flag )
      table[i] = -1 ;
  }

  return table ; 
}

/*
Name - playgame1
Input - n ( Number of Balls) , k ( Number of possible selections) , p( The selections of balls i can make)
Output - void 
Description - In this function we are getting a table for our DP Algorithm from function dptable().
              We then send a corresponding index for each positive value of i , and a random index 
              in case of a (-1) stored at that index . 
              
*/

void playgame1( int n , int k , int p[] )
{
  int *table  ;
  int i ;

  table = dptable ( n , k , p ) ;

  
  for ( i = n ; i > 0 ; )
  { 
    if ( i >= 0)
      i = makemove1( table[i] ) ; 
    else
    {
      int randomI = 0 + rand()%k  ; 
      i = makemove1( randomI ) ;
    }
  }

}
/*
Name - playgame2
Input - n ( Number of Balls) , k ( Number of possible selections) , p( The selections of balls i can make)
Output - void 
Description - We first create the AP sequence of possible selections and store it in modified p.
              Then we find the range in which our i falls in . 
              If it falls in some [ a(p[0]+p[k-1]) , a(p[0]+p[k-1]) + p[0] ) then we are in a losing position hence make a random choice
              If it falls in [ a(p[0]+p[k-1]) + p[0] , (a+1)(p[0]+p[k-1]) ) we make an informed correct choice of index 
              which renders us in a definite winning position.
*/
void playgame2( int n , int k , int p[] )
{ 

  int i ;
  int First , Last , Div , Loss_Start , Win_Start ; 
  for ( i = 1 ; i < k ; i++)
    p[i] = p[0] + i ; 

  First = p[0] ; 
  Last = p[k-1] ;

  for ( i = n ; i > 0 ; )
  {
    Div = i / ( First+Last) ; 
    
    Loss_Start = Div * (First+Last ) ; 
    
    Win_Start = Loss_Start + First ; 

    if ( i < Win_Start )
      {
        int randomI = 0 + rand()%k  ; 
        i = makemove2( randomI ) ;
      }
    else
    {
      if ( i <= Win_Start + First - 1 )
        i = makemove2( 0 ) ;
      else
        i = makemove2( i - (Win_Start+First-1) ) ;
    }

  }



}

int main ( )
{
  int *A, n, k, *p;
  A = registerme();
  n = A[0];
  k = A[1];
  p = A + 2;
  playgame1( n , k , p) ; 
  playgame2( n , k , p ) ; 

}