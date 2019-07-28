/*
Name: Assignment1.cpp
Creator: HIMANSHU MUNDHRA - 16CS10057
PC No. : 70
Date: July 27 , 2017
Description: In this file is the code to find the peak of the integer valued function as 
             mentioned in the question . We have adopted the Divide and Conquer Paradigm to 
             solve this question in Order Logarithmic time with the help of a blackbox1.o 
	     precompiled for our usage provided by the question setter .
*/

#include<iostream>
using namespace std ; 
#include<math.h>

extern void registerme ( const char [] );
extern int evaluate ( unsigned int );
extern void verify ( unsigned int );


/*
Name - findpeak()
Input - Void 
Output - Returns the position of the maxima
Description -
This is the function which enables us to calculate the peak of the function which is implemented via
the black box . In the first while loop we keep on incrementing our variable i such that we reach the
part of the function where it is decreasing. The choice of the base and the exponent were chosen as a 
result of hit and try to get an optimal combination which gives us the answer in least required calls
*/

unsigned int findpeak ()
{
  unsigned Range , Low_Lim , Mid_Point , Up_Limit , Val_Left , Val_Mid , Val_Right ; 
  
  unsigned int Exp = 1  ;

  Range = (int)(pow ( 6 , Exp ))  ;

  Low_Lim = 0 ;

  while(1)
    {
      if ( evaluate(Range) < evaluate (Range+1) )	    //Condition where the function is increasing 
	{
	  Range = (int)(pow ( 5 , Exp+=3 ) ) ;	            //Keep on incrementing the range exponentially to reach the downward region faster
	}  
      else
	{
	  Up_Limit = Range ;
	  break ;
	} 
    }

  while(1)
    {
      Mid_Point = (Low_Lim+Up_Limit)/2 ;
  
      Val_Left = evaluate(Mid_Point-1);
      Val_Mid = evaluate(Mid_Point);
      Val_Right = evaluate(Mid_Point+1);

      if ( Val_Left < Val_Mid  && Val_Mid  > Val_Right )    // The maximum value will be larger than both the numbers on its flanks
	{
	  return Mid_Point ;
	}
      else if ( Val_Left < Val_Mid && Val_Mid < Val_Right ) // Still in the Increasing Part     
	{
	  Low_Lim = Mid_Point+1 ;
	}
      else 						    // In the Decreasing Part			
	{
	  Up_Limit = Mid_Point-1;			   
	}
    }
}

int main ( )
{
  unsigned int n;
  registerme("16CS10057");
  n = findpeak();
  verify(n);
}