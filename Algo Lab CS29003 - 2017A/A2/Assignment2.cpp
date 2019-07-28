/*
Name: Assignment1.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: August 3 , 2017
Description: 
*/

#include<iostream>
using namespace std ; 

#include<math.h>

 
//Merges two arrays 
void merge(int arr[][1000], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
  
    int L[2][n1], R[2][n2];
 
   
    for (i = 0; i < n1; i++)
        {
	  L[0][i] = arr[0][l + i];
      	  L[1][i] = arr[1][l + i];
        }
    for (j = 0; j < n2; j++)
        { 
	  R[0][j] = arr[0][m + 1+ j];
	  R[1][j] = arr[1][m + 1+ j];
	}
 
    
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[0][i] >= R[0][j])
        {
            arr[0][k] = L[0][i];
	    arr[1][k] = L[1][i];
            i++;
        }
        else
        {
            arr[0][k] = R[0][j];
	    arr[1][k] = R[1][j];
            j++;
        }
        k++;
    }
 
    
    while (i < n1)
    {
        arr[0][k] = L[0][i];
	arr[1][k] = L[1][i];
        i++;
        k++;
    }
 
    
    while (j < n2)
    {
        arr[0][k] = R[0][j];
        arr[1][k] = R[1][j];
        j++;
        k++;
    }
}
//Gives Minimum of two numbers
int minimum ( int a , int b )
{
	return a<b ? a : b ;
}

//Sends parts of arrays for merging
void mergesort(int arr[][1000], int n)
{
   int size;  
   int l; 
 
   for (size=1; size<=n-1; size = 2*size)
   {
       
       for (l=0; l<n-1; l += 2*size)
       {
           
           int mid = l + size - 1;
 
           int r = minimum(l + 2*size - 1, n-1);
 
           merge(arr, l, mid, r);
       }
   }
}
//Returns Maximum of the Finishing Time of the counters
int finishingtime ( int a[][1000] , int s[][1000] , int p )
{	
	int i , j ;
	int mainsum = 0 ;
	int sum ;
	for ( i = 0 ; i < p ; i++ )
	{
		for ( j = 1 , sum = 0 ; j <= s[i][0] ; j++ )
		{	
			sum += a[0][ s[i][j] ] ;
		}
		
		if (mainsum < sum ) mainsum = sum ;  ;
	}
	
	return mainsum ;
}
//Returns the total time waited by the Customers 
int totalwaittime( int a[][1000] , int s[][1000] , int p )
{
	int i , j ;
	int mainsum = 0 ;
	int sum ;
	int curr ;
	for ( i = 0 ; i < p ; i++ )
	{
		for ( j = 1 , sum = 0 ; j < s[i][0] ; j++ )
		{	
			sum += a[0][ (s[i][j]) ]*(s[i][0]-j) ; 
		}
		//cout<<" "<<sum<<" " ;
		mainsum += sum ;
	}
	
	return mainsum ; 
}

//Prints the Schedule 
void printschedule( int a[][1000] , int s[][1000] , int p )
{
	int i , j ;
	
	cout<<endl;

	for ( i = 0 ; i < p ; i++ )
	{	
		cout<<"Counter No. "<<i<<" : " ;
 
		for ( j = 1 ; j <= s[i][0] ; j++ )
		{
			cout<<a[1][ (s[i][j]) ]<<"("<<a[0][ s[i][j] ]<<")  " ; 
		}
		cout<<endl;
	}
}
//Minimum element of array is returned
int min ( int arr[] , int p )
{
	int i  , min ;
	for ( i = 1 , min = 0 ; i < p ; i++)
	{
		if ( arr[min] > arr[i] )
			min = i ; 
	}
	return min ;
}

void schedule1( int n , int p , int a[][1000] , int s[][1000] )
{
	
	int f [1000] ;
	int i ;
	for ( i = 0 ; i < p ; i++ )
	{	
		s[i][0] = 1 ;	    //Setting Number of Requests initially at first column
		s[i][1] = i ;	    //Storing the Index of the first allocated request
		f[i] = a[0][i] ;	//Finishing Time Initialisation
	}
	int ind ; 
	for ( i = p ; i < n ; i++ )
	{
		ind = min ( f , p ) ;

		s[ind][0]++;

		s[ind][ ( s[ind][0] ) ] = i ;
		
		f[ind] += a[0][i];
	}

	
}

void schedule2( int n , int p , int a[][1000] , int s[][1000] )
{
	mergesort( a , n );

	/*cout<<"\n\n" ;
	for ( int i = 0 ; i < n ; i++ )
  	{
	  cout<<a[1][i]<<" " ; 		 
  	}
	cout<<"\n\n";
	*/

	schedule1(n,p,a,s);
}

int main ( )
{
  int n , p  ;
  cout<<"\n\nEnter Value of n :" ;
  cin>>n;

  int a[2][1000];
  int s[1000][1000];
	
  cout<<"\nEnter Value of p :" ;
  cin>>p;	
  
  cout<<"\nEnter Time Required :"<<endl ;
  int i ;
  for ( i = 0 ; i < n ; i++ )
  {
	cin>>a[0][i];			//First Row contains Time
	a[1][i]=i;			//Second Row Contains the Token Number 
  }
  cout<<"\n\nFor Schedule 1 :- \n\n";
  schedule1( n , p , a , s );
  printschedule( a , s , p);

  cout<<"\nFinishing Time in Schedule 1: "<<finishingtime(a,s,p)<<endl;

  cout<<"\nTotal Waiting Time in Schedule 1 : "<<totalwaittime(a,s,p)<<endl;

  cout<<"\n\nFor Schedule 2 :- \n\n";
  schedule2( n , p , a , s );
  printschedule( a , s , p);

  cout<<"\nFinishing Time in Schedule 2: "<<finishingtime(a,s,p)<<endl;

  cout<<"\nTotal Waiting Time in Schedule 2: "<<totalwaittime(a,s,p)<<endl<<endl;


}