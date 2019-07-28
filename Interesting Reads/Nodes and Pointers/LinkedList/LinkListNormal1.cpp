/**
 */
#include<iostream.h>
#include<stdio.h>
#include<conio.h>

struct Node
{
	 int data;
	 Node *link;
};//*start;

class LinkListN
{
	 Node *start;
	 public:
	 LinkListN()
	 {
		  start = NULL;
	 }
	 int isEmpty()
	 {
		  if(start == NULL)
				return 1;
		  else
				return 0;
	 }

	 void insertAtBegining(int val)
	 {
		  Node *n_node = new Node;//Creating a new node
		  n_node->data = val;
		  n_node->link = NULL;
				
		  if(start != NULL)       //If list is not empty
				n_node->link = start;
				
		  start = n_node;
	 }

	 void insertAtEnd(int val)
	 {
		  Node *n_node, *next, *prev = NULL;
		  n_node = new Node;//Creating a new node with value
		  n_node->data = val;
		  n_node->link = NULL;
		  
		  if(start == NULL)       //If list is empty, then this is the 1st node
				start = n_node;
		  else
		  {
				prev = start;
				next = start->link;
				while(next != NULL)
				{
					 prev = next;
					 next = next->link;
				}                      
				prev->link = n_node;
		  }
	 }

	 void display()
	 {
		  Node *next = start;
		  while(next != NULL)
		  {
				if(next->link != NULL)
					cout << next->data << " --> ";
				else
					cout << next->data << " !!! ";
					
				next = next->link;
		  }
		  cout << "\n";
	 }

	 void deleteFromBegining()
	 {
		  Node *prev = start;
		  
		  if(isEmpty() == 1)
				cout << "\n Link List Empty.";
		  else
		  {
				start = start->link;
				cout << "\n Node with value " << prev->data << " deleted from begining";
				delete prev;
		  }
	 }

	 void deleteFromEnd()
	 {
		  Node *next, *prev = NULL;
		  int val = 0;	
		  if(isEmpty() == 1)
				cout << "\n Link List Empty.";
		  else
		  {
		    prev = start;
			next = start->link;
			
			if(next == NULL)	// only one samaan in the list 
			{
				start = NULL;
				val = prev->data;
				delete prev;
			}
			
			else
			{
				while(next->link != NULL)
				{
					prev = next;
					next = next->link;
				}
				prev->link = NULL;
				val = next->data;
				delete next;
			}
			
			cout << "\n Node with value " << val << " deleted from 	  }
	 }

	 void search(int val)
	 {
		  int flag = 0;
		  int p = 0;
		  Node *next = start;
		  while(next != NULL)
		  {
				p++;
				if(next->data == val)
				{
					 flag = 1;
					 cout << "\nValue found at position : " << p;
				}
				next = next->link;
		  }
		  if(flag == 0)
				cout << "\nValue not found.";
	 }
};


void main()
{
	LinkListN lls;
	int ch = 0, ans = 0;
	do
	{
		cout << "\n 1.  Insert at beginning ";
		cout << "\n 2.  Insert at end ";
		cout << "\n 3.  Delete from begining";
		cout << "\n 4.  Delete from end";
		cout << "\n 5.  Display ";
		cout << "\n 6.  Search ";
		cout << "\n Enter your choice ";
		cin >> ch;
		int i = 0, v = 0, p = 0, num = 0;
		switch(ch)
		{
			case 1:
				cout << "\nEnter value : ";
				cin >> v;
				lls.insertAtBegining(v);
				break;
			case 2:
				cout << "\nEnter value : ";
				cin >> v;
				lls.insertAtEnd(v);
				break;
			case 3:
				lls.deleteFromBegining();
				lls.display();
				break;
			case 4:
				lls.deleteFromEnd();
				lls.display();
				break;
			case 5:
				cout << "\nThe list is: ";
				lls.display();
				break;
			case 6:
				cout << "\n Entre the value to be searched ";
				cin >> v;
				lls.search(v);
				break;
			default:
				cout << "\n Wrong choice ";
		}
		cout << "\n Do you want to continue ? [for yes enter 1]";
		cin >> ans;
	}
	while(ans == 1);
	cout << "\n End of the process";
}

