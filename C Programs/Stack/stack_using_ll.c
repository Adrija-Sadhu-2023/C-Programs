/*Implement stack using linked list.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *link;
}*top = NULL;

void push ()
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    int data;
    printf ("\n Enter data : ");
    scanf ("%d", &data);
    tmp->info = data;
    tmp->link = top;
    top = tmp;
} 
void pop ()
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    if (top == NULL)
    {
        printf ("\n Underflow");
        return;
    }
    else
    {
        tmp = top;
        printf ("\n The popped element is %d", tmp->info);
        top = top->link;
        free (tmp);
    }
  }

void display ()
{
    struct node *q;
    if (top == NULL)
    {

        printf ("List is empty");
        return;
    }
    q = top;
    while(q)
    {
        printf (" %d", q->info);
        q = q->link;
    }
    printf ("\n");
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
