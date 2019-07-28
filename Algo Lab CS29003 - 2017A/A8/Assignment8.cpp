/*
Name: Assignment8.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: Septemeber 7 , 2017
Description: Use of Hash Tables via chaining
*/
#include<iostream>
using namespace std ;
#include<math.h>
#include<time.h>
#include<stdlib.h>

struct triplet{

    int i ;
	int u ;
	int v ;
};

typedef struct _node {

  int ans ;
  triplet t  ;
  struct _node *next;

} node;

typedef node* nodeP  ;
typedef nodeP* hashT ;

int Max( int a , int b )
{
	if ( a > b )  return a ;
	else return b ;
}


int hashf ( triplet tr , int s )
{
	return (7*tr.i + 3*tr.u + 5*tr.v )%s ;
}


hashT init ( int s)
{
	hashT T ;
	T = ( nodeP*) malloc( s * sizeof(nodeP) );

	for ( int i = 0 ; i < s ; i++)
		T[i] = NULL ;

	return T ;
}

/*
hashT insert ( hashT T , triplet tr , int s )
{

	int k = hashf ( tr , s) ;

	nodeP p = (node*)malloc( sizeof(node) ) ;
	p->t = tr ;
	p->next = T[k] ;
	T[k] = p ;

	return T ;

}


int search ( hashT T , triplet tr , int s )
{
	int k = hashf ( tr , s ) ;

	nodeP p = T[k] ;

	while (p)
	{
		if ( (p->t).i == tr.i && (p->t).u == tr.u && (p->t).v == tr.v )
		{
			return 1 ;
		}

		p = p->next ;
	}

	return 0 ;
}


int exhsearch (  int i , int u , int v , int n , int l , int* a) // Here the Function invariant basically is that whether this current plane in hand
{                                                                // can be inserted or not into any of the two decks.
	int left = 0 ;
	int right = 0 ;

	if (  ( i == n )  || ( u + a[i] > l && v + a[i] > l) )
		return i ;

	if (  !( u + a[i] > l)  )
		left  = exhsearch ( i+1 , u+a[i] , v      , n , l , a) ;

	if (  !( v + a[i] > l)  )
		right = exhsearch ( i+1 , u      , v+a[i] , n , l , a) ;

	return Max (  left , right ) ;

}

int hashsearch ( int i , int u , int v , int n , int l , int* a , hashT T )
{

	if (  ( i == n )  || ( u + a[i] > l && v + a[i] > l) )
		return i ;

	int left = 0 ;
	int right = 0 ;

	triplet tr ;
	tr.i = i+1 ;
	tr.u = u+a[i] ;
	tr.v = v ;

	if (  !( u + a[i] > l)  )
	{
		if( !search( T , tr , n*l ) )
		{
			T = insert ( T ,  tr , n*l ) ;
			left = hashsearch ( i+1 , u+a[i] , v , n , l , a , T  ) ;

		}

	}

	tr.i = i+1 ;
	tr.u = u ;
	tr.v = v+a[i] ;

	if (  !( v + a[i] > l)  )
	{
		if( !search( T , tr , n*l ) )
		{
			T = insert ( T ,  tr , n*l ) ;
			right = hashsearch ( i+1 , u , v+a[i] , n , l , a , T  ) ;

		}

	}

	return Max (  left , right ) ;

 }
*/

int exhsearch (  int i , int u , int v , int n , int l , int* a) // Here if we wish to change the invariant such that check whether last insertion was
{                                                                // viable or not , then the code should be something as follows
	if (  ( i == n+1 )  ||  ( u  > l ) ||  ( v  > l)  )
		return -1 ;

	return 1 + Max (  exhsearch ( i+1 , u+a[i] , v , n , l , a) , exhsearch ( i+1 , u , v+a[i] , n , l , a) ) ;

}

hashT insert ( hashT T , triplet tr , int s , int n )
{

	int k = hashf ( tr , s) ;

	nodeP p = (node*)malloc( sizeof(node) ) ;
	p->t = tr ;
	p->ans = n ;

	p->next = T[k] ;
	T[k] = p ;

	return T ;

}


nodeP search ( hashT T , triplet tr , int s )
{
	int k = hashf ( tr , s ) ;

	nodeP p = T[k] ;

	while (p)
	{
		if ( (p->t).i == tr.i && (p->t).u == tr.u && (p->t).v == tr.v )
		{
			return p ;
		}

		p = p->next ;
	}

	return p ;  // yahan tak pahuncha matlab ki NULL hai yeh
}

int hashsearch ( int i , int u , int v , int n , int l , int* a , hashT T )
{
    int ans ;

	triplet tr ;
	tr.i = i ;
	tr.u = u ;
	tr.v = v ;

	nodeP p = search( T , tr , n*l ) ;

	if ( p )
        return p->ans ;

	if (  ( i == n+1 )  || ( u > l ) || ( v > l) )
		return -1 ;

	ans = 1 + Max (  hashsearch ( i+1 , u+a[i] , v , n , l , a , T ) , hashsearch ( i+1 , u , v+a[i] , n , l , a , T )  ) ;

    T = insert ( T , tr , n*l , ans ) ;

    return ans ;

}





int main ()
{
  int n , l ;
  clock_t c1 , c2 ;
  double runtime ;

  cout<<"\nPlease Enter the value of L and N : ";
  cin>>l>>n;

  int a[n] , i ;

  for ( i = 0 ; i < n ; i++)
  {
  		cin>>a[i];
  }

  c1 = clock();
  int ans1 = exhsearch( 0 , 0 , 0 , n , l , a ) ;
  c2 = clock();

  cout<<"\nThe Number BY Method 1 is  : "<<ans1<<endl ;

  cout<<"\nRunning Time BY Method 1 is : "<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


  cout<<"\n\nA Hash Table is created of size -> "<<l*n<<endl ;
  hashT T = init( n*l ) ;

  c1 = clock();
  int ans2 = hashsearch( 0 , 0 , 0 , n , l , a , T ) ;
  c2 = clock();

  cout<<"\nThe Number BY Method 2 is  : "<<ans2<<endl ;

  cout<<"\nRunning Time BY Method 2 is : "<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


}
