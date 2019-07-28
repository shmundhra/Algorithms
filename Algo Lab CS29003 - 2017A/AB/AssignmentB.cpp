/*
Name: A11.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: November 9 , 2017
Description: Graphs 
*/


#include<iostream>
using namespace std ;
#include<math.h>
#include<bits/stdc++.h>
#include<stdlib.h>

struct _node 
{
	int vertex ; 
	struct _node* next ; 
} ; 
typedef _node* node ;


struct header {

  int sno ;
  int low ; 
  int flag ;
  int grpno ; 
  node L;

} ;

struct graph {

   int n;
   header *H;

} ;


graph gengraph ( )
{

	int i , n , m  ;
	cin>>n ; 
	cin>>m ; 

	graph G ; 
	G.n = n ;

	G.H = new header[n] ;
	for ( i = 0 ; i < n ; i++ )
	{
		(G.H[i]).sno   =   -1 ;
		(G.H[i]).low   =   -1 ;
		(G.H[i]).flag  =   -1 ;
		(G.H[i]).grpno =   -1 ;
		(G.H[i]).L     = NULL ;
	}
	int a , b ;
	
	for ( i = 0 ; i < m ; i++ )
	{
		cin>>a>>b ; 

		node Nnode = new _node ;
		Nnode->vertex = b ;

		node tmp ; 
		tmp = G.H[a].L ;
		G.H[a].L = Nnode ;
		Nnode ->next = tmp ; 
	}

	return G ;
}


void prngraph ( graph G )
{
   int i;
   node p;
   cout<<"\n++The Graph in Adjacency List Format is : \n" ; 

   for (i = 0; i<G.n; ++i) 
   {	

   	  cout<<i<<" -> " ;	
      
      p = G.H[i].L;      
      while (p) 
      {
         cout<<p->vertex<<"  ";
         p = p -> next;
      }
      
      cout<<"\n";
   }
   cout<<endl;
}


void DFS ( graph G , stack<int> *S , int u , int *tim , int *grp , int grpno[] )
{
	S->push(u) ; 

    G.H[u].flag = 1 ; 
    G.H[u].sno = (*tim)++;
    G.H[u].low = G.H[u].sno ; 

    node p;
    
    p = G.H[u].L;      
    
    int v ; 
    
    while (p!=NULL) 
    {	
    	v = p->vertex ;
        

        if ( G.H[v].sno == -1 )
        {
        	DFS ( G  , S  , v , tim , grp , grpno)  ;
        	G.H[u].low = min ( G.H[u].low , G.H[v].low  ) ; 
        }

        else if ( G.H[v].flag == 1 )
        {
        	G.H[u].low = min ( G.H[u].low , G.H[v].sno  ) ; 	
        }

        p = p -> next;
    }

    if ( G.H[u].sno == G.H[u].low )
    {	
    	 cout<<"\n++SubGroup number "<<*grp<<" -> " ;
    	    	 
    	 do 
    	 {
    	 	v = (int)S->top() ; 
    	 	cout<<v<<" " ; 
    	 	S->pop() ; 
    	 	G.H[v].flag  = -1 ;
    	    grpno[v] = *grp ;

    	 } while ( v != u ) ; 
    	 (*grp)++ ;
    }

}

int* findsubgroups( graph G , int *grp) 
{
	stack<int> *S = new stack<int>() ;
	int *grpno = new int[G.n] ; 
	int i , tim  ;
	tim = 0 ;
	

	for ( i = 0 ; i < G.n ; i++ )
	{
		if ( G.H[i].sno == -1 ) 
			DFS ( G  , S  , i , &tim , grp , grpno) ; 
	}
	
	return grpno ; 
}

void essentialsubgroups ( graph G , int g , int grpno[] )
{
	int *gr = new int[g] ; 
	int i ;
	for ( i = 0 ; i < g ; i++ )
	{
		gr[i] = 1 ; 
	}
   
   int a , b , v ; 
   node p;
   for (i = 0; i<G.n; ++i) 
   {	
   	  a = grpno[i];
   	  p = G.H[i].L;      
      
      while (p) 
      {	
      	v = p->vertex ;
      	b = grpno[v] ; 
      		 if ( a != b )
     		 	gr[b] = 0 ;

     	p = p->next ; 
      }
   }
   cout<<"\n\n" ; 
   int c = 0 ;
   for ( i = 0 ; i < g ; i++ )
	{	

		if ( gr[i] == 1 )  
		{	cout<<"Group "<<i<<" is essential "<<endl;
			c++ ;  
		}
	}
	cout<<"\n\nThe Number of Essential Groups is : " << c <<endl<<endl;


   

}


int main ()
{ 
  graph G = gengraph() ;
  prngraph(G) ; 
  int grp = 0 ;
  int* A_grpno = findsubgroups(G , &grp ) ; 
  essentialsubgroups( G , grp , A_grpno ) ; 


}