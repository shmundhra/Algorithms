
/**
 * Description of class Stack -
 * main() : to access Class Stack
 * 
 * Description of class Stack -
 * Class : Stack
 * 
 * Data members :
 * int stck[ ] : the array to hold the integer elements
 * int top      : to point the index of the top element of stack
 * 
 * Methods:
 * Stack(int limit): 
 *                constructor to initialize  top to -1
 * void push (int num) :
 *                to add integer values to the top of stack using 
 *                LIFO (Last In First Out), if possible, else display the message
 *                "Stack Overflow" 
 * int pop( ) : 
 *                to remove the integer from the top of stack using LIFO 
 *                and returns it , if stack is not empty, otherwise output 
 *                the message "Stack Underflow" and returns -9999. 
 * void display( ) : 
 *                to display the integer from the stack using LIFO 
 *                and returns it , if stack is not empty, otherwise output 
 *                the message "Stack Underflow". 
 * int isFull() :
 *                to check whether the stack is full.
 * int isEmpty() :
 *                to check whether the stack is empty.
 *
 *
 *
 * @author (your name)
 * @version (a version number or a date)
 */

#include<iostream.h>
#include<stdio.h>
#include<conio.h>

struct Stack
{
	 int stck[50];
	 int top;
	 int MAX;
};
Stack st;

 //Push integer values to the top of stack
 void push(int num)
 {
	  if (isFull() == 1) cout <<"Stack Overflow";
	  else st.stck[++st.top] = num;
 }
 //Pop integer values from the top of stack
 int pop()
 {
	  if (isEmpty() == 1) return -9999;
	  else return st.stck[st.top--];
 }
 //Check whether the stack is full.
 int isFull()
 {
	  if (st.top == (st.MAX - 1)) return 1;
	  else return 0;
 }
 //Check whether the stack is empty.
 int isEmpty()
 {
	  if (st.top < 0) return 1;
	  else return 0;
 }
 //Display the stack elements
 void display()
 {
	  if (isEmpty() == 1)
			cout << "Stack Underflow";
	  else
			for (int i = st.top; i >= 0; i--)
				 cout << st.stck[i] << "\t";
 }


void main()
{

	int ch,v;
	char a;
	int lmt = 5;
	int result = 0;

	
	st.top = -1;
	st.MAX = lmt;
	
	do
	{
		cout<<"\n 1. INSERT ";
		cout<<"\n 2. DELETE ";
		cout<<"\n 3. DISPLAY";
		cout<<"\n ENTER YOUR CHOICE(1-3) : ";
		cin>>ch;

		if(ch==1)//Push some numbers to stack
		{
			cout<<"\n Enter the value : ";
			cin>>v;
			push(v);
			/*
			cout << "\nElements of Stack after pushing : ";
			display();
			*/
		}
		else if(ch==2)//Pop number from stack
		{
			result = pop();
			if(result == -9999)
				cout << "\nStack Underflow";
			else
				cout << "\nPopped element is : " << result;
			/*
			cout << "\nElements of Stack after poping : ";
			display();
			*/
		}
		else if(ch==3)//Display number from stack
		{
			cout << "\nElements of Stack : ";
			display();
		}
		else
			cout << "\n Invalid choice. GADHA !!!";

		cout<<"\n Do you want to continue? (Y/N) : ";
		cin>>a;
	} while(a == 'Y' || a == 'y');
	getch();
}