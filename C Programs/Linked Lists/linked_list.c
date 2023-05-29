/*Perform the following operations on a linked list using Switch case 
i) create the list 
ii) display its elements 
iii) insert a node at the beginning 
iv) insert a node at a given position
v) delete any given node
vi)search for an element
vii)Sorting the linked list
viii)Reverse the linked list*/
#include<stdio.h> 
#include<stdlib.h>
struct node 
{ 
    int data; 
    struct node *link; 
}*start;

// Creation of link list 
void create_list(int data) 
{ 
    struct node *tmp,*q; 
    tmp=(struct node*)malloc(sizeof(struct node)); 
    tmp->data=data; tmp->link=NULL; 
    if(start==NULL) start=tmp; 
    else 
    { 
        q=start; 
        while(q->link) 
        q=q->link; 
        q->link=tmp; 
    } 
}

//Display of linked list
void display() 
{ 
    struct node *q; 
    if(start==NULL) 
    { 
        printf("List is empty"); 
        return; 
    }
    q=start; 
    while(q) 
    { 
        printf(" %d",q->data); 
        q=q->link; 
    }
    printf("\n"); 
}
//Insert at the beginning
void insert_beg (int data)
{
  struct node *tmp;
  tmp = (struct node *) malloc (sizeof (struct node));
  tmp->data = data;
  tmp->link=start;
  start = tmp;
} 
//Insert at a given position
void insert_pos(int data, int pos)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 1; i < pos; i++)
        q = q->link;
    tmp = malloc (sizeof (struct node));
    tmp->data = data;
    if (q->link != NULL)
    {
        tmp->link = q->link;
        q->link = tmp;
    }
    else
    {
        tmp->link = q->link;
        q->link = tmp;
    }
}
//Delete a node
void deletenode(int data)
{
    struct node *tmp, *q;
    if (start->data == data)
    {
        tmp = start;
        start = start->link;
        free (tmp);
    }
    q = start;
    while (q->link->link != NULL)
    {
        if (q->link->data == data)
        {
            tmp = q->link;
            q->link = tmp->link;    
            free (tmp);
        }
        q = q->link;
    }
    if (q->link->data == data)
    {
        tmp = q->link;
        free (tmp);
        q->link = NULL;
    }
}
//search for an element
void search(int data)
{
    struct node *q;
    int pos = 1;
    q = start;
    while (q != NULL)
    {
        if (q->data == data)
        {
            printf ("\n Element found at position %d", pos);
            return;
        }
    }
    if (q == NULL)
        printf ("\n Not found");
    printf ("\n");
}
//Sorting the linked list
void sort(int n)
{
    int i, j, tmp;
    struct node *p, *q;
    p = start;
    for (i = 0; i < n - 1; i++)
    {
        q = p->link;
        for (j = i + 1; j < n; j++)
        {
            if (p->data > q->data)
                {
                    tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
                }    
            q = q->link;
        }
        p = p->link;
        }
    printf ("\n");
}
//Reverse the linked list
void reverse()
{
    struct node *p1, *p2, *p3;
    if (start->link == NULL)
    {
        printf ("\n Only one node");
        return;
    }
    p1 = start;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;
    p2->link = p1;
    while (p3 != NULL)
    {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }
    start = p2;
}

int main ()
{
    int ch, data, pos, n, i;
    start = NULL;
    printf("\n\n1.Create.\n2.Insert_beg\n3.Insertat_pos\n4.Delete\n5.Search\n6.Sort\n7.Reverse\n8.Display\n9.Exit\n\n");
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
            printf ("\n Enter the data to be inserted at the beginning : ");
            scanf ("%d", &data);
            insert_beg (data);
            break;

            case 3:
            printf("\n Enter the data and position u want to insert in the linked list : ");
            scanf ("%d\n%d", &data, &pos);
            insert_pos (data, pos);
            break;

            case 4:
            printf ("\n Enter the data to be deleted : ");
            scanf ("%d", &data);
            deletenode (data);
            break;

            case 5:
            printf ("\n Enter the data u want to search : ");
            scanf ("%d", &data);
            search (data);
            break;

            case 6:
            sort (n);
            break;

            case 7:
            reverse();
            break;

            case 8:
            printf ("\nThe linked list is:");
            display();
            break;
            
            case 9:
            exit (1);
            default:printf ("\n Invalid choice");
        }
    }
}
