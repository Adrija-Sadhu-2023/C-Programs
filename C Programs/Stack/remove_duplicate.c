/*Remove the duplicate elements from a stack using push() and pop() operations and 
without violating the LIFO concept*/
#include<stdio.h> 
#include<stdlib.h> 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
void push (int value)
{
    struct Node *newNode;
    newNode = malloc (sizeof (struct Node));
    newNode->data = value;
    if (top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
    }
    top = newNode;
    printf ("Node is Inserted\n\n");
}

int pop ()
{
    if (top == NULL)
    {    
        printf ("\nStack Underflow\n");   
    }
    else    
    {  
        struct Node *temp = top;   
        int temp_data = top->data;
        top = top->next;
        free (temp);
        return temp_data;
    }
}
void removeDuplicates () 
{
    struct Node *p1, *p2, *dup;
    p1 = top; 
    while (p1 != NULL && p1->next != NULL)
    {      
        p2 = p1;
        while (p2->next != NULL)
        {
            if (p1->data == p2->next->data)  
            {	      
                dup = p2->next;	      
                p2->next = p2->next->next;
                free (dup);
            }
            else
            p2 = p2->next;	
        }   
        p1 = p1->next;   
    }
}
void display () 
{
    if (top == NULL)   
    { 
        printf ("\nStack Underflow\n");   
    }
    else    
    {      
        printf ("The stack is \n");     
        struct Node *temp = top;
        while (temp->next != NULL)
        {	  
            printf (" %d ", temp->data);	  
            temp = temp->next;
        }
        printf (" %d\n\n ", temp->data);   
    }
}
int main () 
{
    int choice, value; 
    printf ("Stack using Linked List\n");
    while (1)
    {      
        printf (" 1.Push \n 2. Pop \n 3. Display \n 4.Duplicte \n 5. Exit\n");     
        printf ("Enter your choice : ");
        scanf ("%d", &choice);
        switch (choice)
        {	
            case 1:	  
            printf ("\nEnter the value to insert: ");
            scanf ("%d", &value);
            push (value);
            break;
                
            case 2:
            printf ("Popped element is :%d\n", pop ());
            break;
                
            case 3:
            display ();
            break;
                
            case 4:
            removeDuplicates ();
            break;
                
            case 5:  
            exit (0);
            break;
                
            default:
            printf ("\nWrong Choice\n");
        }
    }
}


