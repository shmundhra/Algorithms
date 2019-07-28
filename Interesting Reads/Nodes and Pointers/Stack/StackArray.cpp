#include<iostream.h>
#include<stdio.h>
#include<conio.h>

int st[10];					// All functions use this hence better to declare globally
int top = -1;				// STACK Variable to hold the index position of the top ( latest ) element of the stack 
int MAX = 10;				// Maximum size of the STACK ARRAY , reqd to compare for OVERFLOW

//We start with an array & keep on feeding elements such that ; Later the element was inserted ,greater its index position
//So effectively the TOP index position holds the NEWEST element and the FIRST element is in '0' ; 

 void push(int num)					//Accepts Value of insertion 
 									//JOB : Insertion of element into Stack 
{	  if ( top == (MAX - 1)  )		//		Checks whether insertion is at all possible , Stack mein jagah toh haina . 
		cout <<"Stack Overflow";	//		Agar jagah nahi hai toh user ko message karega ki aapka kaam na ho paye
	  else
		st[++top] = num;			// 		Pre increment of the index postion so that the empty position after top holds num
 }

 int pop()					
 {									//JOB : Deletion of LAST ELEMENT of Stack ( @top in array ) (LIFO)
	  if (top == -1)				//Checks whether any element is even present for deletion 
		return -9999;
	  else
		return st[top--];			//Returning of the POPPED ELEMENT and deletion of the last index position 
 }									//Post Decrement is very essential 


 void display()						
 {											//JOB: Display of elements of the STACK 
	  if (top == -1)						//Checks whether elements are even present for display  
			cout << "Stack Underflow";
	  else
		for (int i = top; i >= 0; i--) 	   //The display starts from the Latest element which is top in the array 
				cout << st[i] << "\t";     //Loop variable moves backward as the array elements are displayed in reverse order
 }										   //of their input ( LAST IN FIRST OUT ~ FIRST IN LAST OUT )


void main()
{

	int ch,v;
	char a;
	int result = 0;

	do
	{
		cout<<"\n 1. INSERT ";
		cout<<"\n 2. DELETE ";
		cout<<"\n 3. DISPLAY";
		cout<<"\n ENTER YOUR CHOICE(1-3) : ";
		cin>>ch;

		if(ch==1)
		{
			cout<<"\n Enter the value : ";
			cin>>v;
			push(st,v);

		}
		else if(ch==2)
		{
			result = pop(st);
			if(result == -9999)
				cout << "\nStack Underflow";
			else
				cout << "\nPopped element is : " << result;

		}
		else if(ch==3)
		{
			cout << "\nElements of Stack : ";
			display(st);
		}
		else
			cout << "\n Invalid choice.!!!";

		cout<<"\n Do you want to continue? (Y/N) : ";
		cin>>a;
	} while(a == 'Y' || a == 'y');
	getch();
}