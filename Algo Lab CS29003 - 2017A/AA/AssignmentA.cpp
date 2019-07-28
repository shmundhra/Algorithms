/*
Name: Assignment10.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: October 26 , 2017
Description: Strings and Sequences 
*/

#include<iostream>
using namespace std ;
#include<math.h>
#include<time.h>
#include<stdlib.h>



int issubseq ( char string[] , char text[] , int sl , int tl)
{
	if ( tl == 0 )
		return 1 ;
	if ( sl == 0)
		return 0 ;

	if ( string[sl-1] == text[tl-1] )
		return  issubseq( string , text , sl-1 , tl-1 ) ;
	else
		return  issubseq( string , text , sl-1 , tl ) ;

}

char* repsymbols( char text[] , int k , int tl )
{
	char* reptext = new char[tl*k+1] ; 

	int i , j ;
	for ( i = 0 ; i < tl ; i++)
	{
		for ( j = 0 ; j < k ; j++)
		{
			reptext[i*k+j] = text [i] ; 
		}
	}

	return reptext ; 

}

void prnsubseq ( char string[] , char text[] , int sl , int tl)
{
	
	int i , j ;

	for ( i = 0 ; i < sl ; i++ )
	{
		cout<<string[i] ; 
	}
	cout<<endl;


	for ( i = 0 , j = 0 ; j < tl ; i++)
	{
		if ( string [i] == text[j] )
		{	
			cout<<text[j] ;
			j++ ;  
		}
		else
		{
			cout<<" " ; 
		}

	}

	while ( i < sl)
	{
		cout<<" ";
		i++ ; 
	}

}

int exhs ( char string[] , char text [] , int sl , int tl)
{

	int k ;
	for ( k = 0 ; k < sl/tl ; k++)
	{
		char * arr = repsymbols( text , k+1 , tl ) ; 
		if ( ! ( issubseq ( string , arr , sl , (k+1)*tl )    )    )
			return k ; 
	}

	return k ;

}

int dnc1 ( char string[] , char text[] , int sl , int tl , int n )
{
	if ( sl < 2*tl)
	{
		if ( issubseq( string , text , sl , tl ) )
			return 1 ;

		return 0 ; 
	}

	int* hash = new int[n]  ;
	for ( int x = 0 ; x < n ; x++ )
		hash[x] = 0 ;  

	char* s1  = new char[sl+1] ;
	char* s2  = new char[sl+1]  ; 

	int i , j , k ;

	for ( i = 0 , j = 0 , k = 0 ; i < sl ; i++ )
	{

		if ( hash [string[i] - 97 ] % 2 == 0 )
		{	
				s1[j] = string[i] ; 
				j++ ; 
				 
		}
		else
		{
				s2[k] = string[i] ; 
				k++ ;
		}

		hash [ string[i] - 97 ] ++ ;

	}
    
	int k1 = dnc1 ( s1 , text , j , tl , n ) ;
	int k2 = dnc1 ( s2 , text , k , tl , n ) ;

	char* arr1 = repsymbols( text , k1+k2+1 , tl ) ; 
	char* arr2 = repsymbols( text , k1+k2   , tl ) ; 
	
	if ( issubseq ( string , arr1 , sl , (k1+k2+1)*tl ) )
		return k1+k2+1 ; 
	if ( issubseq ( string , arr2 , sl , (k1+k2)*tl ) )
		return k1+k2 ; 

	return k1+k2-1 ; 

}
/*


Name - dnc2
Input - char Array string , char Array text , string length sl , text length tl , sigma as n  
Output - Value of k 
Description - In this function we are calculating the value of k ( k1 ) for one half of the array . 
			  Since with the knowledge of k1 we can estimate the value of k2 to be one of { k1 - 1 , k1 , k1 + 1 }  
			  We find through all the permutations the possible values of k and eliminate those in which k though even has k1 != k2
			  We are then left with 2*k1 - 1 , 2*k1 and 2*k1 + 1 as possible values of k 
			  We then perform an exhaustive search
              


*/


int dnc2 ( char string[] , char text[] , int sl , int tl , int n )
{
	if ( sl < 2*tl)
	{
		if ( issubseq( string , text , sl , tl ) )
			return 1 ;

		return 0 ; 
	}

	int* hash = new int[n]  ;
	for ( int x = 0 ; x < n ; x++ )
		hash[x] = 0 ;  

	char* s1  = new char[sl+1] ;
	
	int i , j , k ;

	for ( i = 0 , j = 0 , k = 0 ; i < sl ; i++ )
	{

		if ( hash [string[i] - 97 ] % 2 == 0 )
		{	
				s1[j] = string[i] ; 
				j++ ; 
				 
		}
		hash [ string[i] - 97 ] ++ ;

	}
    
	int k1 = dnc2 ( s1 , text , j , tl , n ) ;
	int k2 = k1 ; 

	char* arr1 = repsymbols( text , k1+k2+1 , tl ) ; 
	char* arr2 = repsymbols( text , k1+k2   , tl ) ; 
	
	if ( issubseq ( string , arr1 , sl , (k1+k2+1)*tl ) )
		return k1+k2+1 ; 
	if ( issubseq ( string , arr2 , sl , (k1+k2)*tl ) )
		return k1+k2 ; 

	return k1+k2-1 ; 

}



int main ()
{ 

   int sl , tl , n ; 
   cin>>n>>sl>>tl;

   char *string = new char [ sl+1 ] ;
   char *text   = new char [ tl+1 ] ;
   
   cin>>string ; 
   cin>>text   ;

   cout<<"S = "<<string<<endl ; 
   cout<<"T = "<<text<<endl<<endl ; 

   cout<<"+++Exhaustive Search : "<<endl ; 
   cout<<"Value of k = "<< exhs ( string , text , sl , tl ) <<endl<<endl ;
   
   cout<<"+++Divide and Conquer 1  : "<<endl ; 
   cout<<"Value of k = "<< dnc1 ( string , text , sl , tl , n ) <<endl<<endl ;
   
   cout<<"+++Divide and Conquer 2  : "<<endl ; 
   cout<<"Value of k = "<< dnc2 ( string , text , sl , tl , n ) <<endl<<endl ;

   int k =  exhs ( string , text , sl , tl ) ; 

   char * arr = repsymbols ( text , k ,tl ) ; 

   cout<<"+++The Subsequence is : \n"<<endl ;
   prnsubseq ( string , arr , sl , k*tl )  ; 
   cout<<endl;


}