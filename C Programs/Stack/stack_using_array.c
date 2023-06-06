/*Implement stack using array*/
#define size 10 
#include<stdio.h>
#include<stdlib.h> 
int top=-1; 
int stack[size];
void push ()
{
    int data;
    printf ("\n Enter the elements : ");
    scanf ("%d", &data);
    if (top == size - 1)
    {
        printf ("\n Overflow");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf ("\n Underflow");
        return;
    }
    else
    {
        printf ("\n The popped element is %d", stack[top]);
        top = top - 1;
    }
}
void display ()
{
    int i;
    if (top == -1)
    {
        printf ("\n Stack is empty");
        return;
    }
    else
    {
        for (i = top; i >= 0; i--)
        printf (" %d", stack[i]);
    }
} 
int main () 
{
    int choice;
    printf ("\n 1.Push \n2.Pop \n3.Display \n4.Exit\n");
    while (1) 
    {
        printf ("\n Enter your choice : ");
        scanf ("%d", &choice);
        switch (choice)	
        {	
            case 1:
            push ();
            break;
            
            case 2:
            pop ();
            break;
                
            case 3:
            display ();
            break;
                
            case 4:
            exit (1);
                
            default:
            printf ("\n Enter a valid choice ");
        }
    }
    return 0;
}


 
 
