#include <iostream>
using namespace std ;
/*#include <conio.h>
#include <stdlib.h>
*/
//LINKED LIST MANE CREATION OF SELF REFERENTIAL STRUCTURE POINTERS ; initialisation always preceeded by *
//Assignment operator in pointers means assignement of that particular element's address in the computers's memory

//structure containing a data part and link part
struct node
{
	int data;
	node *next;
} *top;

/* node* CrNO ( int val )
{
	node *n_node = new node ;
	n_node->data = num;
	n_node->next = NULL ;
	return n_node ;
}*/


//Adds a node at the top(begining of linked list)
void push(int num)
{
  //Creation of new node ;
	node *n_node = new node;		//Allocation of free space
	n_node->data = num;
	n_node->next = NULL ;
	// node * n_node = CrNO(num) ;


	n_node->next = top;	 // TOP holds the address of the element which was top till now. Now this new node is top and
						// to maintain link it holds the address of that (top) element which is currently stored in TOP
	top = n_node;	   // Since the previously top element has been replaced ,the top pointer has to be updated with new TOP
}

//Display the contents of List
void display()
{
	node *tmp = top;		// THE NODE with help of which we will TRAVERSE in the Stack
	int c = 0;				// Since the display starts from top (Last in First OUT ), we set the Traversal NODE  with TOP

	if(top == NULL)			// routine check is made
	{
		  cout<<"\nStack Underflow\n";
	}

	else
	{
		  cout<<"\nThe contents of Stack :\t";
		  while(tmp != NULL)
		  {
				cout << tmp->data << ", ";
				tmp = tmp->next;				//Increment operation in LINKED LISTS .
				c++;
		  }
		  cout << "\nNo. of nodes in the Stack : " << c;
	 }
}

//Deletes a node from the top(begining of linked list)
void pop()
{
	 node *tmp = top;
	 if(top == NULL)
	 {
		  cout<<"\nStack Underflow\n";
	 }

	 else
	 {
	  top = top->next; //top is assigned the memory of the element whose address is stored in the link part of that element
	  delete tmp;	  //whose address top holds right now , double jump kindof , increment operator in linked lists .
	 }
}


//MAIN
int main()
{
	top = NULL;//Empty Stack.

	int c = 0, pos = 0, item = 0, val = 0;
//	clrscr();

	while (1)
	{
		//clrscr();
		cout << "\n1. Enter element  ";
		cout << "\n2. Delete element ";
		cout << "\n0. EXIT";
		cout << "\n Enter your choice : ";
		cin >> c;

		if(c == 1)
		{
			cout << "\nEnter element (value) in stack : ";
			cin >> item;
			push(item);
		}
		else if(c == 2) pop();
		else if(c == 0) exit(0);
		//Display number from Stack
		cout << "\nElements of Stack : ";
		display();
		cout << "\nEnter to continue ... ";
		//getch();
	}
}
