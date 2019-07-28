/*
Name: Assignment6.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: August 24 , 2017
Description: 
*/

#include<iostream>
using namespace std ; 
#include<cstdlib>

typedef struct _tnode {

  int key;
  struct _tnode *L,*R;

} tnode;

typedef tnode *bstree;

void print ( bstree T , int l )
{
	if ( T == NULL)
		return ;

	print ( T->L , l+1 );

	int i ;
	for ( i = 0 ; i <= l ; i++ )
		cout<<"\t";
	cout<<T->key<<endl;

	print ( T->R , l+1 );

}

/*

bstree Insert( bstree T , int val )
{
	if ( T == NULL )
	{
	     bstree N = new tnode ; 
	     N->key = val ; 
	     N->L = N->R = NULL ;	      
	     return N ; 
	}	
	else
	{		 
		if  ( T->key > val ) T->L = Insert( T->L , val ) ; 
		else if ( T->key < val ) T->R = Insert( T->R , val ) ; 
		else return T ; 
	}
}

bstree TreeInsert( )
{
	bstree T = new tnode ; T = NULL ; 

	int n ; cin>>n ; 

	int val ; 
	for ( int i = 0 ; i < n ; i++ )
	{
		cin>>val ; 
		T = Insert( T , val ) ; 
	}
	return T ; 
}


*/
bstree TreeInsert (  )
{
	int i , n , val ; 
	bstree T = (bstree)malloc(sizeof(tnode));
	T = NULL ;   

	cin>>n;
	for ( i = 0 ; i < n ; i++ )
	{
		cin>>val;
		bstree N = (bstree)malloc(sizeof(tnode));
		N-> key = val ; 
		N-> L = NULL ;
		N-> R = NULL ; 

		bstree X = (bstree)malloc(sizeof(tnode));
		bstree Y = (bstree)malloc(sizeof(tnode));

		Y = NULL ; 
		X = T ;

		while ( X != NULL )
		{
			Y = X ;
			if ( N -> key <  X -> key)
				X = X -> L ;
			else
				X = X -> R ; 
		}

		if ( Y == NULL )
			T = N ;
		else if ( N-> key < Y -> key )
			Y-> L = N;
		else
			Y-> R = N ;
	}

	return T ;

}

bstree LeftRotate ( bstree T )
{
	bstree Pivot = T -> R ; 

	T -> R = Pivot -> L ;
	Pivot -> L = T ;
	
	return Pivot ;
}

bstree RightRotate ( bstree T )
{
	bstree Pivot =  T -> L ; 

	T -> L = Pivot -> R ;
	Pivot -> R = T ;
	

	return Pivot ;
}

bstree FlatLeft ( bstree T )
{
	if ( T == NULL )
		return NULL ; 

	
	while ( T-> R != NULL )
	{
		T = LeftRotate(T);
	}
	
	
	T->L = FlatLeft(T->L);
	return T ;
}


bstree FlatRight ( bstree T )
{
	if ( T == NULL )
		return 0 ; 

	
	while ( T-> L != NULL )
	{
		T = RightRotate(T);
	}
	

	T->R = FlatRight(T->R);
	return T ;
}


bstree Flattened ( bstree T )
{
	T-> L = FlatLeft(T->L) ;
	T-> R = FlatRight(T->R);
	return T ;
}

void PrintDLL ( bstree LL )
{
	bstree prev = NULL ;
	bstree curr = LL ;


	while ( curr != NULL )
	{
		cout<<curr->key<<" " ;
		prev = curr ;
		curr = curr-> R ;
	}
	cout<<endl;

	curr = prev ;
	prev = NULL ;

	while ( curr != NULL )
	{
		cout<<curr->key<<" " ;
		prev = curr ;
		curr = curr->L ;
	}
	cout<<endl;

}

bstree tree2list ( bstree T )
{
	T = Flattened ( T ) ;

	cout<<"+++ The Flattened Tree is : " << endl ;
	print ( T , 0) ;

	bstree prev = NULL ;
	bstree curr = NULL ;

	prev = T ;
	curr = T->R ;
	while ( curr != NULL )
	{
		curr->L = prev ;
		prev = curr ;
		curr = curr -> R ;
	}

	prev = T ;
	curr = T->L ;
	while ( curr != NULL )
	{
		curr->R = prev ;
		prev = curr ;
		curr = curr -> L ;
	}
	cout<<"\n\n";
	PrintDLL( prev ) ;
	
	T = prev ; 

	return T ; 

}



bstree list2tree ( bstree T ) 
{	

	bstree prev = NULL ;
	bstree curr = NULL ; 
	bstree next = NULL ;

	cout<<" qwqw " ;  

	
	int i , n = 0 ;
	curr = T ;

	while ( curr != NULL )
	{
		n++ ; 
		curr = curr -> R ;
	}

	if ( n == 0 )	
		return NULL ; 


	curr = T ;

	for ( i = 1 ; i <= n/2 + 1 ; i++ )
	{
		curr = curr->R ; 
	}

	prev = curr -> L ;
	next = curr -> R ;

	prev -> R = NULL ; 
	next -> L = NULL ;

	curr->R = list2tree ( curr -> R ) ;
	curr->L = list2tree ( T ) ;
	T = curr ; 
	return T ; 

}

int main ()
{	
	bstree T = 	TreeInsert();
	cout<<endl;

	cout<<" +++ Initial Tree : " <<endl ;
	print( T , 0);
	cout<<endl;
	
	cout<<endl;

	T = tree2list ( T ) ;

	cout<<endl ;

	T = list2tree ( T ) ;
	print ( T , 0 ) ;

	return 0 ;
}