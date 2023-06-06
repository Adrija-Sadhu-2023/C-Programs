/*Implement a DE queue using an array.*/
#include<stdio.h> 
#include<stdlib.h>
#define MAX 5 
int deque_arr[MAX];
int left = -1;
int right = -1;
void input_que();
void output_que();
void insert_right ()
{
    int added_item;
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf ("Queue Overflow\n");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (right == MAX - 1)
        right = 0;
    else
        right = right + 1;
    printf ("\n Input the element for adding in queue : ");
    scanf ("%d", &added_item);
    deque_arr[right] = added_item;
}

void insert_left ()
{
    int added_item;
    if ((left == 0 && right == MAX - 1) || (left == right + 1))
    {
        printf ("Queue Overflow \n");
        return;
    }
    if (left == -1)
    {
        left = 0;
        right = 0;
    }
    else if (left == 0)
        left = MAX - 1;
    else
        left = left - 1;
    printf ("\n Input the element for adding in queue : ");
    scanf ("%d", &added_item);
    deque_arr[left] = added_item;
}

void delete_left ()
{
    if (left == -1)
    {
        printf ("Queue Underflow\n");
        return;
    }
    printf ("\n Element deleted from queue is : %d\n", deque_arr[left]);
    if (left == right)
    {
        left = -1;    
        right = -1;
    }
    else if (left == MAX - 1)
        left = 0;
    else
        left = left + 1;
}

void delete_right ()
{
    if (left == -1)
    {
        printf ("Queue Underflow\n");
        return;
    }
    printf ("\n Element deleted from queue is : %d\n", deque_arr[right]);
    if (left == right)
    {
        left = -1;
        right = -1;
    }
    else if (right == 0)
        right = MAX - 1;
    else
        right = right - 1;
}

void display_queue ()
{
    int front_pos = left, rear_pos = right;
    if (left == -1)
    {
        printf ("Queue is empty\n");
        return;
    }
    printf ("\n Queue elements :\n");
    if (front_pos <= rear_pos)
    {
        while (front_pos <= rear_pos)
        {
           printf ("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf ("%d ", deque_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf ("%d ", deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf ("\n");
}

void input_que () 
{
    int choice;
    do
    {
        printf ("\n 1.Insert at right ");
        printf ("\n 2.Delete from left ");
        printf ("\n 3.Delete from right ");
        printf ("\n 4.Display ");
        printf ("\n 5.Insert as output restricted queue ");
        printf ("\n\n Enter your choice : ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
            insert_right ();
            break;

            case 2:
            delete_left ();
            break;

            case 3:
            delete_right ();
            break;

            case 4:
            display_queue ();
            break;

            case 5:
            output_que();
            break;

            case 6:
            exit(1);

            default:
            printf ("Wrong choice\n");
        }
    }
    while (choice);
    printf("\n");
}

void output_que ()
{
    int choice;
    do
    {
        printf ("\n 1.Insert at right ");
        printf ("\n 2.Insert at left ");
        printf ("\n 3.Delete from left ");
        printf ("\n 4.Display ");
        printf ("\n 5.Insert as input restricted queue ");
        printf ("\n\n Enter your choice : ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1:
            insert_right ();
            break;

            case 2:
            insert_left ();
            break;

            case 3:
            delete_left ();
            break;

            case 4:
            display_queue ();
            break;

            case 5:
            input_que();
            break;

            case 6:
            exit(1);
            break;

            default:
            printf ("Wrong choice\n");
        }
    }
    while (choice);
}

int main ()
{
    int choice;
    printf ("\n 1.Input restricted dequeue ");
    printf ("\n 2.Output restricted dequeue ");
    printf ("\n\n Enter your choice : ");
    scanf ("%d", &choice);
    switch (choice)
    {
        case 1:
        input_que ();
        break;

        case 2:
        output_que ();
        break;

        default:
        printf ("Wrong choice\n");
    }
    return 0;
}
