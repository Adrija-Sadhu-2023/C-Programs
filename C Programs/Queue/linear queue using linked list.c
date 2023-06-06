/*Implement a linear queue using a linked list.*/
#include <stdio.h> 
#include <stdlib.h>
struct node 
{ 
    int data;  
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert (int value) 
{ 
    struct node *ptr;   
    ptr = (struct node *) malloc (sizeof (struct node));
    ptr->data = value;
    ptr->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;   
    }
    else   
    {
        rear->next = ptr;
        rear = ptr;    
    }
    printf ("node is Inserted\n\n");
}

int delete () 
{ 
    if (front == NULL)       
    {
        printf ("\nUnderflow\n");       
        front = rear = NULL;	// after delteing all elements both should point to NULL
        return -1; 
    }
    else 
    { 
        struct node *temp = front; 
        int temp_data = front->data; 
        front = front->next;
        free (temp);
        return temp_data;
    }
}

void display () 
{
    struct node *temp;   
    if ((front == NULL) && (rear == NULL))
    {
        printf ("\nnode is Empty\n");       
    }    
    else        
    {        
        printf ("The node is \n");       
        temp = front;
        while (temp)
        {
            
            printf ("%d--->", temp->data); 
            temp = temp->next;
        }
        printf ("NULL\n\n");
    }
}
int main () 
{ 
    int choice, value;
    printf ("\nImplementation of node using Linked List\n");
    while (1)
    {    
        printf ("\n 1.insert \n 2.delete \n 3.Display \n 4.Exit\n");       
        printf ("\nEnter your choice : ");
        scanf ("%d", &choice);
            
        switch (choice)
        {    
            case 1:   
            printf ("\nEnter the value to insert: ");
            scanf ("%d", &value);
            insert (value);
            break;
                
            case 2: 
            printf ("deleted element is :%d\n", delete ());
            break;
        
            case 3:        
            display ();
            break;
                
            case 4:
            exit (1);
                
            default:
            printf ("\nIncorrect Entry\n");
        }
    }
    return 0;
}  
