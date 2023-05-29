/*Perform the following operations on a linked list using Switch case 
i) create the list 
ii) display its elements 
iii) insert a node at the beginning 
iv) insert a node at a given position
v) delete any given node*/
#include<stdlib.h>
#include<stdio.h>
struct node
{
  int info;
  struct node *link;
}*last;
//Creating the circular linked list
void create_list (int data)
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    if (last == NULL)
    {
        last = tmp;
        tmp->link = last;
    }
    else
    {
        tmp->link = last->link;
        last->link = tmp;
        last = tmp;
    }
}
//Displaying the circular ll
void display ()
{
    struct node *q;
    if (last == NULL)
    {
        printf ("\n List is empty");
        return;
    }

    q = last->link;
    while (q != last)
    {
        printf (" %d", q->info);
        q = q->link;
    }
    printf (" %d", last->info);
}
//Insert at the begining of the circular ll
void insert_beg (int data)
{
    struct node *tmp;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
} 

//Insert at a given position
void insert_pos (int data, int pos)
{
    struct node *tmp, *q;
    int i;
    q = last->link;
    for (i = 0; i < pos - 1; i++)
        q = q->link;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
    if (q == last)
        last = tmp;
}
//Delete a node
void delete_node (int data)
{
    struct node *q, *tmp;

    q = last->link;
    if (q->info == data)
    {
        tmp = q;
        last->link = tmp->link;
        free (tmp);
        return;
    }
    while (q->link->info == data)
    {
        if (q->link->info == data)
        {
            tmp = q->link;
            q->link = tmp->link;
            free (tmp);
            return;
        }
        q = q->link;
    }
    if (q->link->info == data)
    {
        tmp = q->link;
        q->link = tmp->link;
        free (tmp);
        last = q;
    }
}

int main ()
{
    last = NULL;
    int ch, data, pos, n, i;
    printf("\n\n1.Create.\n2.Display\n3.Insert at the beginning\n4.Insert at a given position\n5.Delete a given node \n6.Exit\n\n");
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
