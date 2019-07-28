/*
Name: Assignment6.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: Septemeber 7 , 2017
Description: 
*/


#include<iostream>
using namespace std ; 
#include<cstdlib>

#define lim 500 

typedef struct _tnode {

  int size ;
  struct _tnode *P;

} tnode;

typedef tnode * tree ; 

void initrooms (  tree R[][lim] , int m , int n)
{	
	int i , j ;
	
	for ( i = 0 ; i < m ; i++)
		for ( j = 0 ; j < n ; j ++)
		{	
			R[i][j] = new tnode ; 
			R[i][j]->size = 1 ;
			R[i][j]->P = R[i][j] ;
		}

}

tree findroot ( int i , int j , tree R[][lim] )
{	
	tree N =  R[i][j] ;
	tree A =  R[i][j] -> P ;

	while ( N != A )
	{
		N = A ;
		A = A->P ; 
	}
	return N ; 
}

void mergeregions ( tree *x , tree *y  )
{
	if ( (*x)->size < (*y)->size )
	{
		(*x)->P = (*y) ;
		(*y)->size += (*x)->size ; 
	}

	else
	{
		(*y)->P = (*x) ;
		(*x)->size += (*y)->size ; 
	}
	
}



int printlabyrinth( int H[][lim] , int V[][lim] , int m , int n )
{	
	int i , j ;

	for ( i = 0 ; i < n ; i++ )
	{
		cout<<"+---";
	}cout<<"+"<<endl;

	for ( i = 0 ; i < m ; i++ )
	{		
		
			cout<<"|" ;
			for ( j = 0 ; j < n ; j++ )
			{
				if ( V[i][j] )
					cout<<"   |";
				else
					cout<<"    ";
			}
			cout<<endl;
			
			cout<<"+";
			for ( j = 0 ; j < n ; j++ )
			{
				if ( H[i][j])
					cout<<"---+";
				else
					cout<<"   +";	
			}
			cout<<endl;	

	}
	return 0 ;

}

int buildlabyrinth ( int H[][lim] , int V[][lim] , tree R[lim][lim]  , int m , int n )
{	
	int a , b ;
	tree root1 , root2 ; 

	for ( int wr = 0 ; wr < m*n - 1   ;  ) 
	{	
		a = rand() % ( m ) ;
		b = rand() % ( n ) ;
		
		if ( a < m-1 )
		{
			if ( H[a][b] == 1)
			{			
				root1 = findroot ( a   , b , R );
				root2 = findroot ( a+1 , b , R );
				if ( root1 != root2)
				{
					mergeregions ( &root1 , &root2 ) ;
					H[a][b] = 0 ; 
					wr++ ; 
				}
			}
		}

		if ( b < n-1 )
		{
			if ( V[a][b] == 1)
			{			
				root1 = findroot ( a   , b , R );
				root2 = findroot ( a   , b+1 , R );
				if ( root1 != root2)
				{
					mergeregions ( &root1 , &root2 ) ;
					V[a][b] = 0 ; 
					wr++ ; 
				}
			}
		}	
			 
			
						
	}

	return 0 ; 

}

int main ()
{
	
	int i , j ;
	int m , n ;
	cin>>m>>n ;

	int H[lim][lim] , V[lim][lim] ;

	tree R[lim][lim] ;

	initrooms( R , m , n ) ; 

	for ( i = 0 ; i < m ; i++ )			// H[m-1][j] is always = 1 
		for ( j = 0 ; j < n ; j++)
			H[i][j] = 1 ;

	
	for ( i = 0 ; i <m ; i++ )			// // V[i][n-1] is always = 1 
		for ( j = 0 ; j < n ; j++)
			V[i][j] = 1 ;

	cout<<"+++The Initial Labyrinth - \n" ;
	printlabyrinth( H , V , m , n ) ; 

	cout<<"\n+++The Final Labyrinth - \n" ;

	buildlabyrinth( H , V , R , m , n ) ;

    
	printlabyrinth( H , V , m , n ) ; 
	

}