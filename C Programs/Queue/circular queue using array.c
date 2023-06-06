/*) Implement a circular queue using an array.*/
#include <stdio.h> 
#include<stdlib.h> 
#define SIZE 50 
int cq[SIZE];
int rear = -1;
int front = -1;
void insert ()
{
    int data;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf ("\n Overflow");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == SIZE - 1)
        rear = 0;
        else
        rear++;
    }
    scanf ("%d", &data);
    cq[rear] = data;
}

void delete_data ()
{
    if (front == -1)
    {
        printf ("\n Underflow");
        return;
    }
    printf ("\n The deleted element is %d", cq[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {        
        if (front == SIZE - 1)
        front = 0;
        else
        front++;
    }
}

void display ()
{
    int front_pos = front;
    int rear_pos = rear;
    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
            printf (" %d ", cq[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= SIZE - 1)
        {
            printf (" %d ", cq[front_pos]);
            front_pos++;
        }
    }
    front_pos = 0;
    printf("\n");
}

int main ()
{
    int choice;
    while (1)
    {
        printf ("\n 1.Insert element to queue ");
        printf ("\n 2.Delete element from queue ");
        printf ("\n 3.Display all elements of queue ");
        printf ("\n 4.Quit \n");
        printf ("\n Enter your choice : ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("\n Enter the element : ");
            insert ();
            break;

            case 2:
            delete_data ();
            break;
            
            case 3:
            printf("\n The queue is : ");
            display ();
            break;

            case 4:
            exit (1);
            default:
            printf ("Wrong choice \n");
        }
    }
}
