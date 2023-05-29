/*Let a single linked list consists of positive integers in such a way that
 the summation of node values (INFO part) in some continuous nodes matches to the value in the next node.
 For example,  the linked list consists of values 2, 1, 3, 5, 3, 9, 17, 2, 4,6, 
 where 2 + 1 =3 { i.e.summation of 1 st and 2 nd node matches to 3 rd node }, 5 + 3 + 9 =17 and so on.Here,
 no.of summation groups are 2 and values in each summation group are {2, 1},{5, 3, 9}. 
 Write a C code to display the no.of summation groups and the values in each summation group.
*/
#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{
    int data;
    struct Node *next;
};
void create_list (struct Node **head, int data) 
{
    struct Node *tmp, *q;
    tmp = (struct Node *) malloc (sizeof (struct Node));
    tmp->data = data;
    tmp->next = NULL;
    
    if (*head == NULL)
    *head = tmp;
    else
    {    
    q = *head;   
    while (q->next)
        q = q->next;
    q->next = tmp;   
    }
}

int sequence (struct Node *head) 
{
    struct Node *temp1 = head;
    struct Node *temp2 = head;
    int curSum = 0;
    int count = 0;
    while (temp1)
    {
        temp2 = temp1;
        while (temp2->next)
        {
            curSum += temp2->data;
            if (curSum == temp2->next->data)
            {
                printf ("\n %d ", curSum);
                count++;
            }
            temp2 = temp2->next;
        }
        curSum = 0;
        temp1 = temp1->next;
    }   
    return count;     
} 
int main () 
{
    int data, n, i, a; 
    struct Node *head;
    head = NULL; 
    printf ("\n Enter the size for the linked lists:");
    scanf ("%d", &n);
    printf ("\n Enter the data for the linked lists: ");
    for (int i = 0; i < n; i++)
    { 
    scanf ("%d", &data);
    create_list (&head, data);
    } a = sequence (head);
    printf ("\n Total number of summation groups : %d", a);
    return 0;
}


 
 
 
 
