/*Perform the following operations on a doubly linked list using Switch case 
i) create the list 
ii) display its elements 
iii) insert a node at the beginning 
iv) insert a node at a given position
v) Delete a node from the list*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
}*start;
//Create a doubly linked list
void create_list (int data)
{
    struct node *tmp, *q;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    tmp->next = NULL;
    if (start == NULL)
    {
        tmp->prev = NULL;
        start = tmp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
}
//Display the list
void display ()
{
    struct node *q = start;
    if (start == NULL)
    {
        printf ("\n List is empty ");
        return;
    }
    else
    {
        while (q != NULL)
        {
            printf (" %d", q->info);
            q = q->next;
        }
    }
}
//Insert at the beginning
void insert_beg (int data)
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
} 
//Insert at a given position
void insert_pos (int data, int pos)
{
    struct node *q, *tmp;
    int i;
    q = start;
    for (i = 1; i < pos; i++)
        q = q->next;
    tmp = (struct node *) malloc (sizeof (struct node));

    tmp->info = data;
    q->next->prev = tmp;
    tmp->next = q->next;
    tmp->prev = q;
    q->next = tmp;
} 
//Delete a node
void delete_node (int data)
{
    struct node *tmp, *q;
    if (start->info == data)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free (tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        if (q->next->info == data)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            free (tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->info == data)
    {
        tmp = q->next;
        q->next = NULL;
        free (tmp);
        return;
    }
}

int main ()
{
    start = NULL;
    int ch, data, pos, n, i;
    printf("\n\n1.Create.\n2.Display\n3.Insert at the beginning\n4.Insert at a given position \n5.Delete a node from the list\n6.Exit\n\n");
    while (1)
    {
        printf ("\n Enter your choice : ");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1:
            printf ("\n Enter the size for the linked lists:");
            scanf ("%d", &n);

            printf ("\n Enter the data for the linked lists: ");
            for (int i = 0; i < n; i++)
            {
                scanf ("%d", &data);
                create_list (data);
            } 
            break;

            case 2:
            printf ("\n Display the elements : ");
            display ();
            break;

            case 3:
            printf ("\n Enter the data to be inserted at the beginning : ");
            scanf ("%d", &data);
            insert_beg (data);
            break;

            case 4:
            printf("\n Enter the data and position u want to insert in the linked list : ");
            scanf ("%d\n%d", &data, &pos);
            insert_pos (data, pos);
            break;

            case 5:
            printf ("\n Enter the data to be deleted : ");
            scanf ("%d", &data);
            delete_node (data);
            break;

            case 6:
            exit (1);
            default:

            printf ("\n Invalid choice");
        }
    }
}
