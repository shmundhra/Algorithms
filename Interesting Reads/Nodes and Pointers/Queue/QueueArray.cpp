/**
 * Description of class Queue -
 * main() : to access Class Queue
 *
 * Description of class Queue -
 * Class : Queue
 *
 * Data members :
 * int que[ ] : the array to hold the integer elements
 * int front  : to point the index of the first element of queue
 * int rear   : to point the index of the last element of queue
 *
 * Methods:
 * Queue(int limit):
 *                constructor to initialize 0 in each memory cell of que[ ]
 *                and front and rear to -1
 * void enqueue (int num) :
 *                to add integer values to the rear of queue using
 *                FIFO (First In First Out), if possible, else display the message
 *                "Queue Overflow"
 * int dequeue( ) :
 *                to remove the integer from the front of queue using FIFO
 *                and returns it , if queue is not empty, otherwise output
 *                the message "Queue Underflow" and returns 0.
 * void display( ) :
 *                to display the integer from the queue using FIFO
 *                and returns it , if queue is not empty, otherwise output
 *                the message "Queue Underflow".
 * boolean isFull() :										// IMPORTANT STUFF
 *                to check whether the queue is full.
 * boolean isEmpty() :										// IMPORTANT STUFF
 *                to check whether the queue is empty.
 *
 *
 *
 * @author (your name)
 * @version (a version number or a date)
 */


#include<iostream.h>
#include<stdio.h>
	
	int que[50];					//Queue Variables
	int front = -1, rear = -1; 		//Rear to store the index position of last  element which changes after insertion
	int MAX = 6;					//Front to store the index position of first element which changes after deletions 
	 
	 //Check whether the queue is full.
	 int isFull()
	 {
		  if ((rear == (MAX - 1))) 
				return 1;		
		  else 
				return 0;
	 }
	 
	 //Check whether the queue is empty.
	 int isEmpty()
	 {
		  if (front < 0 )
				return 1; 	
		  else 
				return 0;
	 }
	 
	 //Insert integer values to the rear of queue	*** ADVANCED ***
	 void enqueue(int num)
    {
        if (isFull() == 1) 
			cout << "Queue Overflow";
        
		else 
        {
            if (isEmpty() == 1) 	//If queue is empty then front and rear value will be set to zero. 
            {
                front = 0;			//Works only with rear except for this case where front and rear both have to be reset. 
                rear = 0;
            }
            else 					// if rear value is less than (max - 1), then rear value is incremented.
                rear = rear + 1;
        
            que[rear] = num;
        }
    }
    
	//Delete integer values from the front of queue
	 int dequeue()					//JOB : Deletion of first element 
	 {
		  if (isEmpty() == 1)  		// Checks whether it can even perform its task 
		  		return -9999;
		  		  
		  else
		  {
				int temp = que[front];	// Store value of deleted element to be displayed later 

				if(front == rear)//If there was only one element in queue, then after deletion queue will become empty
				{				 //The deque function operates basically on front except this case where rear has to be reset
					 front = -1;
					 rear = -1;
				}
				
				else // Otherwise the value of front variable is incremented
				{
					 front = front + 1;
				}

				return temp;			//return the value which is being deleted by us 
		  }
	 }
	 
	 //Display the queue elements
	 void display()
	 {
		  if (isEmpty() == 1)
				cout << "Queue Underflow";
		  else
				for (int i = front; i <= rear; i++)  // front se rear tak 
					 cout << que[i] << "\t";
	 }


void main()
{
	int result = 0;

	//Push some numbers to Queue
	
	for (int i = 0; i < MAX; i++) enqueue(i + 2);

	//Display number from Queue
	
	cout << "\nElements of Queue after enqueuing : ";
	display();

	//Pop number from Queue
	
	result = dequeue();
	if(result == -9999)
		cout << "\nQueue Underflow";
	else
		cout << "\nDequed element is : " << result;
					
	//Display number from Queue
	cout << "\nElements of Queue after dequeuing : ";
	display();        
}