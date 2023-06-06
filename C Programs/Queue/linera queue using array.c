/*Implement a linear queue using an array.*/
#include<stdio.h> 
#include<stdlib.h> 
#define SIZE 50 
int queue_array[SIZE]; 
int rear = -1;
int front = -1;

void insert ()
{
    int data;
    if (rear == SIZE - 1)
        printf ("Queue Overflow \n");
    else
    {
        if (front == -1)
        front = 0;
        printf ("\nInsert the element in queue : ");
        scanf ("%d", &data);
        rear = rear + 1;
        queue_array[rear] = data;
    }
}

void delete_data ()
{
    if (front == -1 || front > rear)
    {
        printf ("Queue Underflow \n");
        return;
    }
    else
    {
        printf ("\n Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display () 
{
    int i;   
    if (front == -1)
    printf ("Queue is empty \n");
    else
    {
        printf ("\n Queue is : ");
        for (i = front; i <= rear; i++)
        printf (" %d", queue_array[i]);
        printf ("\n");        
    }
}

int main () 
{ 
    int choice;
    while (1)
    {    
        printf ("\n1.Insert element to queue ");  
        printf ("\n2.Delete element from queue ");
        printf ("\n3.Display all elements of queue ");
        printf ("\n4.Quit \n");
        printf ("\nEnter your choice : ");
        scanf ("%d", &choice);
        switch (choice)  
        {
            case 1:       
            insert ();
            break;
                
            case 2:
            delete_data();
            break;
                
            case 3:
            display ();
            break;
                
            case 4:
            exit (1);
                
            default:
            printf ("Wrong choice \n");
        }
    }
}


