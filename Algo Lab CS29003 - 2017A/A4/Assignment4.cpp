/*
Name: Assignment4.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: August 17 , 2017
Description: We perform many manipulations on a Binary Tree in the Assignment
*/

#include<iostream>
using namespace std ; 
#include<cstdlib>

typedef struct _tnode {

  int key;
  struct _tnode *L,*R;

} tnode;

typedef tnode* bintree;

/*
Name - buildtree 
Input - n ( Number of Nodes )
Output - The Tree containing all the keys in proper format .
Description - In this function we are building each level of our tree with the user providing the keys and the distribution of
              the remaining nodes between the left and the right child .
*/  

bintree buildtree ( int n )
{

  bintree T;
  
  int n1, n2;
  
  if (n <= 0) return NULL;
  
  T = (bintree)malloc(sizeof(tnode));
  
  cin>>T->key ;
  
  if (n == 1) 
  {
    T -> L = T -> R = NULL;
  } 
  else 
  {
    cin>>n1 ;
    n1 = n1 % n ;                                                                                                                                                                                         
    n2 = (n - 1) - n1;

    T -> L = buildtree(n1);
    T -> R = buildtree(n2);
  }
  return T;

}

/*
Name - mini 
Input - Two Numbers ( Integers) a and b 
Output - The Minimum of the two numbers 
Description - In this function we return the minimum of two numbers .
*/ 

int mini ( int a , int b )
{
  return a > b ? b : a ;
}


/*
Name - printtree
Input - Tree ( bintree type ) , Level ( int )
Output - void 
Description - We are Simply Printing the Tree in this function , with proper indentation. 
              
*/

void printtree ( bintree T , int Level )
{

  int i ;
  for ( i = 0 ; i < (Level+1)*4 ; i++)
  {
      if ( i < Level*4)
        cout<<" ";
      
      else
        cout<<"-" ;
  }


  if ( T == NULL )
    {
      cout<<"NULL"<<endl;
      return ;
    }

  else
    cout<<T->key;

  cout<<endl;

  printtree ( T->L , Level+1) ; 
  printtree ( T->R , Level+1) ; 
 
}

/*
Name - lefttilt 
Input - the Tree T 
Output - Height of the tree  
Description - We in this function are at each step comparing the height of the left and the right subtrees , if the right one being bigger
              we simply swap the children and return 1 + max ( left_height , right_height ) 
 */

int lefttilt ( bintree T )
{
  if ( T == NULL )
    return -1 ;

  int Left_Height , Right_Height ; 

  Left_Height = lefttilt ( T-> L ) ;
  Right_Height = lefttilt ( T-> R) ;
  

  if ( Right_Height > Left_Height)
  { 
    bintree temp  ; 
    temp = T -> L ; 
    T -> L = T -> R ;
    T -> R = temp ;
    
    return Right_Height+1 ;

  }

  else return Left_Height+1 ;

}

/*
Name - updatekeys 
Input - the Level of the Root of the Subtree sent , Total Height , an Auxillary Array holding ancestral values ,the Subtree T 
Output - Void ( though in the function we are updating the keys of all the nodes )
Description - We understand that because we need to move from the leaf to the node and due to the absence of parent pointers , 
              we simply apply a Post Order Traversal . After tackling a node's children when we reach it , we update its key with 
              the required ancestor's value . This ensures that our updation is carried out bottom-up without the loss of data 
 */

void updatekeys( int Level , int Height , int Aux[] , bintree T )
{ 
  if ( T == NULL )
      return ;

  Aux[Level] = T->key ;
  updatekeys( Level+1 , Height , Aux , T -> L ) ;
  updatekeys( Level+1 , Height , Aux , T -> R ) ;

  int anc = mini ( (T->key) % Height , Level )  ; 

  T->key = Aux[Level-anc] ;

}



int main ( )
{
   int n , Height ;
   cin>>n;

   bintree T = buildtree (n) ; 
   
   cout<<"\nThe Initial Tree is : "<<endl;
   printtree( T , 0 ) ; 
   
   Height = lefttilt( T );

   cout<<"\nThe Left Tilted Tree is : "<<endl;
   printtree ( T , 0) ; 
   
   cout<<"\nThe Height of the tree is : " << Height ;

   int Anc[Height+10] ;

   cout<<"\nThe Updated Tree is : "<<endl ;
   updatekeys(0 , Height , Anc , T) ;
   printtree ( T , 0) ; 
   

}