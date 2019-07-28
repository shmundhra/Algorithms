/*
Name: Assignment5.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: August 24 , 2017
Description: In the program we are given as input an array of length N, but we can apply a sorting algorithm to an array of atmost the size s .
             This is a memory constrained (Quick) Sorting Algorithm
*/

#include<iostream>
using namespace std ;
#include<cstdlib>

/*
Name - Minimum
Input - Two integers
Output - An integer
Description - Returns th minimum of the two integers
 */

int Minimum ( int a , int b )
{
    return a > b ? b : a ;
}

/*
Name - Get_Max
Input - Array A , Index Array Q
Output - An integer
Description - Returns the maximum value in the array , 0th Element -> the Root of the Max Heap
 */

int Get_Max( int A[] , int Q[] )
{
    return A[Q[0]] ;
}
/*
Name - MaxHeapify
Input - Array A , Index i , Index Array Q2 , Length N
Output - Void
Description - Heapifies the MaxHeap at the index i ( the Heap is stored in the form of index positions in Q2 such that
              A[ Q2[0....N-1] ] gives the MaxHeap ). We swap only the indexes in the Q2 Array ,  A remains unaltered
 */

void MaxHeapify( int A[] , int i , int Q2[] , int N )
{
    int Left_Child , Right_Child , Large ;

    Left_Child = 2*i + 1 ;
    Right_Child = Left_Child+1 ;

    Large = i ;
    if ( Left_Child < N  && A[ Q2[Left_Child] ] > A[ Q2[Large] ] )
        Large = Left_Child ;
    if ( Right_Child < N &&  A[ Q2[Right_Child] ] > A[ Q2[Large] ] )
        Large = Right_Child ;

    if ( Large != i)
    {
      int temp = Q2[i] ;
      Q2[i] = Q2[Large] ;
      Q2[Large] = temp ;
      MaxHeapify( A , Large , Q2 , N ) ;
    }

}

/*
Name - Make_MaxHeap
Input - Array A , Index Array Q2 , Index Array I2 , Length N
Output - Void
Description - Builds the MaxHeap by actually forming the Array Q2 using MaxHeapify . We also make the corresponding I2 array such
              that Q2[ I2[ i ] ] = i .
*/

void Make_MaxHeap( int A[] , int Q2[] , int I2[] , int N )
{
  int i , j ;
  for (  i = 0 ; i < N ; i++)
  {
    Q2[i] = i ;
  }

  for ( i = N/2-1 ; i>=0 ; i--)
  {
    MaxHeapify ( A , i , Q2 , N ) ;

  }

  for ( i = 0 ; i < N ; i++ )
  {
      j = Q2[i]  ;
      I2[j] = i ;
  }


}
/*
Name - Get_Min
Input - Array A , Index Array Q
Output - An integer
Description - Returns the minimum value in the array , 0th Element -> the "Root" of the Min Heap
 */

int Get_Min( int A[] , int Q[] )
{
    return A[Q[0]] ;
}

/*
Name - Min_Heapify
Input - Array A , Index i , Index Array Q1 , Length N
Output - Void
Description - Heapifies the MinHeap at the index i ( the Heap is stored in the form of index positions in Q1 such that
              A[ Q1[0....N-1] ] gives the MinHeap ). We swap only the indexes in the Q1 Array ,  A remains unaltered
 */


void Min_Heapify( int A[] , int i , int Q1[] , int N )
{
    int Left_Child , Right_Child , Small ;

    Left_Child = 2*i + 1 ;
    Right_Child = Left_Child+1 ;

    Small = i ;
    if ( Left_Child < N  && A[ Q1[Left_Child] ] < A[ Q1[Small] ] )
        Small = Left_Child ;
    if ( Right_Child < N &&  A[ Q1[Right_Child] ] < A[ Q1[Small] ] )
        Small = Right_Child ;

    if ( Small != i)
    {
      int temp = Q1[i] ;
      Q1[i] = Q1[Small] ;
      Q1[Small] = temp ;
      Min_Heapify( A , Small , Q1 , N ) ;
    }


}

/*
Name - Make_MinHeap
Input - Array A , Index Array Q1 , Index Array I1 , Length N
Output - Void
Description - Builds the MinHeap by actually forming the Array Q1 using Min_Heapify . We also make the corresponding I1 array such
              that Q1[ I1[ i ] ] = i .
*/

void Make_MinHeap( int A[] , int Q1[] , int I1[] , int N )
{
      int i , j ;
      for ( i = 0 ; i < N ; i++)
      {
          Q1[i] = i ;
      }

      for ( i = N/2-1 ; i>=0 ; i--)
      {
          Min_Heapify ( A , i , Q1 , N ) ;
      }

      for ( i = 0 ; i < N ; i++ )
      {
          j = Q1[i]  ;
          I1[j] = i ;
      }


}

/*
Name - MinReplace
Input - Array A , Length N , Index Array Q1 , Index Array Q2  , Index Array I1 , Index Array I2 , Integer V
Output - Void
Description - Replaces the Minimum element in the heap and then does the respective changes in the MinHeap by Heapifying at 0
              and in the MaxHeap by doing a process similar to MaxInsert
*/

void MinReplace ( int A[] , int N , int Q1[] , int Q2[] , int I1[] , int I2[] , int v )
{
        int i , j , Parent ;

        i = Q1[0] ;                                         // index of minimum element in the original array

        A[i] = v ;
        Min_Heapify( A , 0  , Q1 , N );

        j = I2[i] ;                                         // index of the minimum element in the max heap

        Parent = (j+1)/2 - 1 ;

        while (  Parent >= 0 &&  A[ Q2[j] ] > A[ Q2[Parent] ]  )
        {
           int temp = Q2[j] ;
           Q2[j] = Q2[Parent] ;
           Q2[Parent] = temp ;

           j = Parent ;
           Parent = (j+1)/2 - 1 ;

        }

        for ( i = 0 ; i < N ; i++ )
        {
          j = Q1[i]  ;
          I1[j] = i ;
        }
        for ( i = 0 ; i < N ; i++ )
        {
          j = Q2[i]  ;
          I2[j] = i ;
        }
}

/*
Name - MaxReplace
Input - Array A , Length N , Index Array Q1 , Index Array Q2  , Index Array I1 , Index Array I2 , Integer V
Output - Void
Description - Replaces the Maximum element in the heap and then does the respective changes in the MaxHeap by Heapifying at 0
              and in the MinHeap by doing a process similar to MinInsert.
*/

void MaxReplace ( int A[] , int N , int Q1[] , int Q2[] , int I1[] , int I2[] , int v )
{

        int i , j , Parent ;

        i = Q2[0] ;                                             // index of maximum element in the original array

        A[i] = v ;
        MaxHeapify( A , 0  , Q2 , N  );

        j = I1[i] ;                                             // index of the maximum element in the min heap

        Parent = (j+1)/2 - 1 ;

        while ( Parent >= 0 && A[ Q1[j] ] < A[ Q1[Parent] ] )
        {
           int temp = Q1[j] ;
           Q1[j] = Q1[Parent] ;
           Q1[Parent] = temp ;

           j = Parent;
           Parent = (j+1)/2 - 1 ;
        }

        for ( i = 0 ; i < N ; i++ )
        {
          j = Q1[i]  ;
          I1[j] = i ;
        }
        for ( i = 0 ; i < N ; i++ )
        {
          j = Q2[i]  ;
          I2[j] = i ;
        }
}

/*
Name - Heap_Sort
Input - Array A , Indexes Start and Last,  Index Array Q2  , Array H
Output - Void
Description - HeapSorts on the MaxHeap and Stores the elements in a separate array H
*/

void Heap_Sort ( int A[] , int Start , int Last , int Q2[] , int H[]  )
{

       while ( Start <= Last )
       {
            H[Last]  = Get_Max ( A , Q2 ) ;
            Q2[0] = Q2[Last] ;
            Last-- ;
            MaxHeapify( A , 0 , Q2 , Last-Start+1 ) ;

       }

}
/*
Name - Quick_Sort
Input - Integer S , Array M , Indexes Start and End
Output - Void
Description - Performs a Memory Constrained Quick Sort using all the above functions.
              Copies S elements of M into A . Puts the elements smaller than Min(A) in L and larger than Max(A) in R
              The elements in between are put in A with each insertion resulting in either the Maximum or the Minimum to be
              copied to R or L respectively . We heapify at positions 0 after each insertion , both Max and Min Heapify .
              After we get our L A R , we heap sort elements of A into H and then copy LHR into M in same order and then
              recurse on L and R .
              The Case for N <= S is taken care of implicitly in the program.
              Our Base case is when any of the Arrays has a 0 Length.
*/

int Quick_Sort(int S, int M[], int Start, int End )
{
    if ( Start > End ) return 0;

    int *A , *Q1 , *Q2 , *I1 , *I2 , *L , *R , *H ;
    int i ;
    int N = End - Start + 1 ;
    int L_Size = 0 ;
    int R_Size = 0 ;

    A  = new int [S+10]  ;
    H  = new int [S+10]  ;
    L = new int [N-S+10]  ;
    R = new int [N-S+10]  ;

    Q1 = new int [S+10]  ;
    Q2 = new int [S+10]  ;
    I1 = new int [S+10]  ;
    I2 = new int [S+10]  ;

    A[ S+1 ] = {0} ;
    H[ S+1 ] = {0} ;
    L[ End - Start - S] = {0} ;
    R[ End - Start - S] = {0} ;

    for ( i = 0 ; i <= Minimum ( S-1 , N-1 ) ; i++ )     // Array A has been made A[0..1..2...]
           A[i] = M[i+Start] ;

    int A_Size = i ;

    Make_MinHeap( A , Q1 , I1 , A_Size ) ;
    Make_MaxHeap( A , Q2 , I2 , A_Size ) ;

    int Min = Get_Min ( A, Q1 ) ;
    int Max = Get_Max ( A, Q2 ) ;

    int Flag = 0 ;
    for ( i = A_Size + Start ; i <= End ; i++ )
    {
            if ( M[i] <= Min )
                L[L_Size++] = M[i] ;

            else if ( M[i] >= Max )
                R[R_Size++] = M[i] ;

            else
            {
                if ( Flag%2 == 0 )
                {
                        L[L_Size++] = Min ;
                        MinReplace ( A , A_Size , Q1 , Q2 , I1 , I2 , M[i] ) ;
                        Min = Get_Min( A , Q1 ) ;
                        Max = Get_Max( A , Q2 ) ;
                        Flag++ ;
                }
                else
                {
                        R[R_Size++] = Max ;
                        MaxReplace ( A , A_Size , Q1 , Q2 , I1 , I2 , M[i] ) ;
                        Min = Get_Min( A , Q1 ) ;
                        Max = Get_Max( A , Q2 ) ;
                        Flag++ ;
                }
            }
    }

    Heap_Sort ( A , 0 , A_Size-1 , Q2 , H );

    for ( i = 0 ; i < L_Size ; i++)
            M[i+Start] = L[i] ;

    for ( i = 0 ; i < A_Size ; i++ )
            M[i+Start + L_Size] = H[i] ;

    for ( i = 0 ; i < R_Size ;i++ )
            M[i + Start + L_Size + A_Size] = R[i] ;


    delete []  Q1 , Q2 , I1 , I2 , A , H , L , R ;

    Quick_Sort( S , M , Start                    , Start + L_Size - 1                    ) ;
    Quick_Sort( S , M , Start + L_Size + A_Size  , Start + L_Size + A_Size + R_Size - 1  ) ;
}

int main ( )
{
   int N , S ;

   cin>>N>>S;

   int M[N] ;

   int i ;
   for ( i = 0 ; i < N ; i++)
         cin>>M[i];

   Quick_Sort( S , M , 0 , N-1  );

   cout<<endl<<endl;

   for ( i = 0 ; i < N ; i++ )
        cout<<M[i]<<" " ;

}
