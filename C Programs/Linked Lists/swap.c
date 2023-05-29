/*Swap the data of two consecutive pairs of nodes, 
starting from the first node. 
Like data of node 1 will be swapped with node 2, 3 with 4, 5 with 6, and so on. 
(Use single linked list).*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
}*start=NULL;
void create(int data)
{
    struct node *tmp,*q;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    tmp->next = NULL;
    if (start == NULL)
    start = tmp;
    else
    {
        q = start;
        while (q->next)
        q = q->next;
        q->next = tmp;
    }
}

void display ()
{
    struct node *q;
    if (start == NULL)
    {
        printf ("List is empty");
        return;
    }
    q = start;
    while (q)
    {
        printf (" %d", q->info);
        q = q->next;
    }
    printf ("\n");
}

void swap (int n)
{
    struct node *q;
    if (start == NULL)
    {
        printf ("List is empty");
        return;
    }
    q = start;
    int tmp;
    printf ("\n The list is : ");

    display ();
    printf ("\n Swapped List : ");
    for (int i = 1; i <= n / 2; i++)
    {
        tmp = q->info;
        q->info = (q->next)->info;
        q->next->info = tmp;
        q = q->next->next;
    }
} 
int main ()
{
    int n, data;
    printf ("\n Enter the size for the linked lists:");
    scanf ("%d", &n);
    printf ("\n Enter the data for the linked lists: ");
    for (int i = 0; i < n; i++)
    {
        scanf ("%d", &data);
        create (data);
    } swap (n);
    display ();
}

