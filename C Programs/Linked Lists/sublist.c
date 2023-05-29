/*Split an original single linked list into two sub-lists, 
where the first sub-list contains the even position nodes 
and the second sub-list contains the odd position nodes. 
Join the first sub-list at the end of the second sub-list. 
Example: If the list contains 3->4->2->1->7->9->8, 
then the First sub-list will be 4->1->9 and 
the Second sub-list will be 3->2->7->8. 
The output will be 3->2->7->8->4->1->9.*/
#include <stdio.h> 
#include <stdlib.h> 
struct node
{
    int data;
    struct node *next;
} *head, *even, *odd, *join;

struct node *head = NULL;
struct node *even = NULL;
struct node *odd = NULL;
struct node *join = NULL;
void create ()
{
    struct node *tmp;
    int n;
    printf ("Enter the no. of node to create: ");
    scanf ("%d", &n);
    head = malloc (sizeof (struct node));
    head->next = NULL;
    printf ("Enter data for node 1: ");
    scanf ("%d", &(head->data));
    tmp = head;
    for (int i = 2; i <= n; i++)
    {
        struct node *newnode;
        newnode = malloc (sizeof (struct node));
        newnode->next = NULL;
        printf ("\nEnter data for node %d: ", i);
        scanf ("%d", &(newnode->data));
        tmp->next = newnode;
        tmp = tmp->next;
    }
} 
void  sub_list () 
{ 
    struct node *tmp, *q, *p; 
    tmp = head;
    even = malloc (sizeof (struct node));
    odd = malloc (sizeof (struct node)); 
    int count = 1; 
    while (tmp->next != NULL)
    {    
        count++;     
        tmp = tmp->next;  
    } 
    odd->next = NULL;
    odd->data = head->data;
    even->next = NULL; 
    even->data = head->next->data;
    p = odd; 
    q = even;
    tmp = head->next->next; 
    for (int i = 3; i <= count; i++) 
    {   
        if (i % 2 == 0)
        {
            struct node *newnode;  
            newnode = malloc (sizeof (struct node));
            newnode->next = NULL;
            newnode->data = tmp->data;
            q->next = newnode;
            q = q->next;
            tmp = tmp->next;
        }
        else
        {
            struct node *newnode; 
            newnode = malloc (sizeof (struct node));
            newnode->next = NULL;
            newnode->data = tmp->data;
            p->next = newnode;
            p = p->next;
            tmp = tmp->next;
        }
    }
} 
void display_even () 
{
    struct node *t; 
    t = even;
    printf ("\n");
    while (t->next != NULL)
    {
        printf ("%d->", t->data);   
        t = t->next;
    }
    printf ("%d", t->data);
}
void display_odd () 
{
    struct node *t; 
    t = odd;
    printf ("\n");
    while (t->next != NULL)
    {      
    printf ("%d->", t->data);     
    t = t->next;
    }
    printf ("%d", t->data);
} 
void sub_join () 
{
    struct node *tmp, *q, *p, *r; 
    tmp = head;
    int count = 1, c_odd = 1, c_even = 1;
    while (tmp->next != NULL)
    {     
        count++;     
        tmp = tmp->next;
    }
    join = malloc (sizeof (struct node)); 
    join->next = NULL;
    join->data = odd->data;
    p = odd->next;
    q = even;
    r = join;
    tmp = odd;
    while (tmp->next != NULL)
    {      
        c_odd++;     
        tmp = tmp->next;
    }
    tmp = even; 
    while (tmp->next != NULL)
    {      
        c_even++;     
        tmp = tmp->next;
    }
    while (c_odd > 1)   
    {      
        struct node *newnode;     
        newnode = malloc (sizeof (struct node));
        newnode->next = NULL;
        newnode->data = p->data;
        r->next = newnode;
        r = r->next;
        p = p->next;
        c_odd--;
    } 
    while (c_even > 0)    
    {      
        struct node *newnode;     
        newnode = malloc (sizeof (struct node));
        newnode->next = NULL;
        newnode->data = q->data;
        r->next = newnode;
        r = r->next;
        q = q->next;
        c_even--;
    }
} 
void display_join () 
{
    struct node *t; 
    t = join;
    printf ("\n");
    while (t->next != NULL)
        {
    printf ("%d->", t->data); 
    t = t->next;
    }
    printf ("%d", t->data);
} 
void main () 
{
    create ();
    sub_list ();
    printf ("The 1st sublist:"); 
    display_even (); 
    printf ("\nThe 2nd sublist:");
    display_odd ();
    sub_join ();
    printf ("\nThe final joined sublist:"); 
    display_join ();
} 
