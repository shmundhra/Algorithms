/*
Name: Assignment9.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: October 12 , 2017
Description: Linear Sorting using Counting Sort and Probabilistic Distribution of Input
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define RM 501

/*

Name - generate_array
Input - int Array a , int n
Output - Array with CGPAs according to Probabilty Distribution
Description - In this function we are generating a random CGPA array with the Probability Distribution

*/

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void generate_array ( int *a , int n )
{

	float p[5] = { 0.05 , 0.2 , 0.3 , 0.3 , 0.15 } ;

	int i , j , ans , ub ;
	int m = 5 ;
	float q[5];
	float y ;

	for ( i = 1 , q[0] = p[0] ; i < m ; i++ )
	{
		q[i] = p[i] + q[i-1] ;
	}


	for ( i = 0 ; i < n ; i++ )
	{
		y = (float)( rand()%RM ) / RM ;

		for ( j = 0 ; j < m ; j++ )
		{
			if ( y <= q[j] )
			{
				ub = j ;
				break ;
			}
		}


		switch ( ub )
		{
			case 0 :  ans = rand() % 101 ;
					  break ;

			case 1 :  ans = 101 + rand() % 100 ;
					  break ;

			case 2 :  ans = 201 + rand() % 100 ;
					  break ;

			case 3 :  ans = 301 + rand() % 100 ;
					  break ;

			case 4 :  ans = 401 + rand() % 100 ;
					  break ;

			default : break ;
		}

		a[i] = ans ;

	}

}

/*

Name -  partition
Input - int Array a , int l , int u
Output - pivot element's correct position
Description - Elementary Quick Sort accesory function



int partition ( int *a , int l , int u )
{
	int x = a[l] ;
	int i = l ;
	int temp , j ;

	for ( j = l+1 ; j <= u ; j++)
	{
		if ( a[j] <= x)
		{
			i++ ;
			temp = a[i] ;
			a[i] = a[j] ;
			a[j] = temp ;
		}
    }
		temp = a[l];
		a[l] = a[i];
		a[i] = temp;


	return i ;
}
*/

/*

Name -  quicksort
Input - int Array a , int l , int u
Output - Sorted Array in the end of all the recursive calls
Description - Recursive Inline QuickSort implementation



void quicksort ( int *a , int l , int u )
{
	if ( l < u)
	{
		int r = partition ( a , l , u) ;
		quicksort ( a , l , r-1 ) ;
		quicksort ( a , r+1 , u)  ;
	}
}

*/
/*

Name -  countingsort1
Input - int Array a , int n
Output - Sorted Array
Description - ELementary Stable Counting Sort
*/
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int length = end - start + 1 ;
        int pivot_pos = start + rand() % length ;

        swap ( &arr[pivot_pos] , &arr[end] ) ;

        int pivot = arr[end];    // pivot

        int i = (start - 1);        // Index of smaller element
        for (int j = start; j <= end- 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap( &arr[i] , &arr[j] ) ;
            }
        }

        swap( &arr[i + 1] , &arr[end]  ) ;
        int left_pivot_pos = i+1 ;

        i = left_pivot_pos ;
        for (int j = left_pivot_pos + 1 ; j <= end ; j++)
        {
            if (arr[j] == arr[left_pivot_pos] )
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        int right_pivot_pos = i ;

        quicksort(arr, start , left_pivot_pos - 1);
        quicksort(arr, right_pivot_pos + 1 , end);
    }
}


void countingsort1 ( int a[] , int n )
{

	int b[n] ;
	int c[501] ;
	int i , k = 501 ;

	for ( i = 0 ; i < k ; i++ )
		c[i] = 0 ;

	for (  i = 0 ; i < n ; i++)
		c[ a[i] ] ++ ;

	for ( i = k-1 ; i > 0 ; i-- )
		c[i] = c[i-1] ;
	c[0] = 0 ;

	for ( i = 1 ; i < k ; i++ )
		c[i] += c[i-1] ;

	for ( i = 0 ; i < n ; i++ )
	{
		b[ c[ a[i] ] ]	= a[i] ;
		c[ a[i] ]++ ;
	}

	for ( i = 0 ; i < n ; i++ )
		a[i] = b[i] ;


}

/*

Name -  countingsort2
Input - int Array a , int n
Output - Sorted Array
Description - ELementary  Counting Sort without auxillary output array
*/

void countingsort2 ( int *a , int n )
{

	int c[501] = { 0 } ;
	int pos = 0 ;
	int i , j , k = 501 ;

	for (  i = 0 ; i < n ; i++)
		c[a[i]]++ ;

	for ( i = 0 ; i < k ; i++ )
	{
		for ( j = 0 ; j < c[i] ; j++ )
			a[pos++] = i ;
	}

}

int main ()
{
  int n , i ;
  clock_t c1 , c2 ;
  double runtime ;

  cout<<"\nPlease Enter the N : ";
  cin>>n;


  int *a = new int[n] ;
  int *b = new int[n] ;
  int *c = new int[n] ;

  c1 = clock();
  generate_array( a,n ) ;
  c2 = clock();

  cout<<"\nRunning Time for Generation is : "<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


  for ( i = 0 ; i < n ; i++)
  {
  		b[i] = a[i] ;
  }


  for ( i = 0 ; i < n ; i++)
  {
  		c[i] = a[i] ;
  }
  cout<<"\nRunning Time BY QuickSort is ( Please wait for 7 seconds) : " ;

  c1 = clock();
  quicksort( a, 0 , n-1 ) ;
  c2 = clock();

  cout<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


  c1 = clock();
  countingsort1( b,n ) ;
  c2 = clock();

  cout<<"\nRunning Time BY CountingSort1 is : "<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


  c1 = clock();
  countingsort2( c,n ) ;
  c2 = clock();

  cout<<"\nRunning Time BY CountingSort2 is : "<< (double)(c2-c1)/(double)CLOCKS_PER_SEC <<endl ;


}
