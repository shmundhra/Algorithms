
//*******************************************************************
	
	void insertAfterValue(int val , int num)
     {
        Node *n_node, *next;
        		
		int f = 0;
		next = start;
		while(next != NULL)
		{ 
			if(num == next->data)
			{
				f++;
				
				n_node = new Node;
				n_node->data = val;
				n_node->link = next->link;
				next->link = n_node;
				break;				
			}
			next = next->link;
		}
        if(start == NULL)       
            cout<<"\nLink List is empty ";
        else if(f == 0)
            cout<<"\n Search value not found";
        else
			cout<<"\n Value inserted ";
     }
//******************************************************************
	 void insertBeforeValue(int val , int num)
     {
        Node *n_node, *next, *prev = NULL;
        n_node = new Node;
		n_node->data = val;
		n_node->link = NULL;
        if(start == NULL)       
            cout<<"\nLink List is empty ";
        else if(num == start->data)
        {
            n_node->link = start;
            start = n_node;
        }
        else
        {
            prev = start;
            next = start->link;
            while(next != NULL)
            { 

                if(num == next->data)
                {
                    n_node->link = next;
                    prev->link = n_node;
                    break;
                }
                prev = next;
                next = next->link;                
            }
        }
     }
	 //*************************************************
	 void insertAtPoint(int val,int pos)
     {
        Node *n_node, *next, *prev = NULL;
        n_node = new Node;
		n_node->data = val;
		
        int count = 1;
        int flag = 0;
        if(pos == 1)
        {
            n_node->link = start;
            start = n_node;
        }
        else
        {
            prev = start;
            next = start->link;
            while(next != NULL)
            {            
                count++;
                if(count == pos)
                {
                    prev->link = n_node;
                    n_node->link = next;
                    flag++;
                    break;
                }
                prev = next;
                next = next->link;
            }
            if(count == (pos-1))
            {
                prev->link = n_node;
				n_node->link = NULL;
                flag++;
            }
            if(flag == 0)
                cout << "\n position out of bounds";
            else
                cout << "\n value inserted at given position";
        }

     }