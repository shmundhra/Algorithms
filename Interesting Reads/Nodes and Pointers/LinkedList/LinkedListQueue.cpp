#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//structure containing a data part and link part
struct node
{
	int data;
	node *next;

} *front,*rear;

//Adds a node at the rear (end of linked list)
void enqueue(int num)
{
	node *n_node = new node;	 // Creation of NODE 
	n_node->data = num;
	n_node->next = NULL;

	if( rear == NULL)		// Queue is empty 
	{
		front = n_node;
		rear = n_node;
	}
	else
	{
		rear->next = n_node;   // rear ka link mein jo node ka address hai ,us ka link mein new node ka address ghusa raha hai
		rear       = n_node;		  // rear mein naya latest node ka address 
	}
}

//Display the contents of List
void display()
{
	node *tmp = front;
	int c = 0;

	if(front == NULL)
	{
		  cout<<"\nQueue Underflow\n";
	}
	
	else
	{
		  cout<<"\nThe contents of Queue :\t";
		  while(tmp != NULL) // while (tmp) ; 
		  {
				cout << tmp->data << ", ";
				tmp = tmp->next;
				c++;
		  }
		  cout << "\nNo. of nodes in the queue : " << c;
	 }
	 
	 delete tmp;
//Deletes a node from the front (begining of linked list)
}
void dequeue()
{
	 node *tmp = front;					
	
	 if(front == NULL)
	 {
		  cout<<"\nQueue is Empty\n";
	 }

	 else
	 {
		  front = front->next;
		  delete tmp;                   // IMPORTANT TO DELETE THE ORIGINAL FRONT TO FREE THE ALLOCATED SPACE
	 }
}	

//MAIN
void main()
{
	front = NULL;//Empty linked list.
	rear = NULL ;

	int c = 0, item = 0;
	clrscr();

	while (1)
	{
		//clrscr();
		cout << "\n1. Enter element ";
		cout << "\n2. Delete element ";
		cout << "\n0. EXIT";
		cout << "\n Enter your choice : ";
		cin >> c;

		if(c == 1)
		{
			cout << "\nEnter element (value) in queue : ";
			cin >> item;
			enqueue(item);
		}
		else if(c == 2)
		     dequeue();
		else if(c == 0) exit(0);
		//Display number of queue
		cout << "\nElements of queue : ";
		display();
		cout << "\nEnter to continue ... ";
		getch();
	}
}
