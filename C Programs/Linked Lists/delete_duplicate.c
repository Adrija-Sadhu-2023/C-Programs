/*. Delete the duplicate nodes in a single linked list. 
For example, if input is: 1->3->3->3->5->6, then output should be 1->3->5->6.*/
#include<stdio.h> 
#include<stdlib.h> 
struct Node
{
  int data;
  struct Node *next;
}*head;
struct Node *deleteDuplicates (struct Node *head)
{
    if (!head || !head->next)
    {
      return head;
    }
    struct Node *ptr1 = head;
    struct Node *ptr2 = head->next;
    while (ptr2)
    {
        if (ptr1->data == ptr2->data)
        {
            ptr2 = ptr2->next;
        }
        else
        {
            ptr1->next = ptr2;
            ptr1 = ptr1->next;
        }
    }
    ptr1->next = NULL;
    return head;
}

int len (struct Node *head)
{
  int size = 0;
  struct Node *temp = head;
  while (temp)
    {
      temp = temp->next;
      size++;
    }
  return size;
}

void sortList (int n)
{
    struct Node *h = head;
    for (int i = 0; i < n - 1; i++)
    {
        struct Node *temp = head;
        for (int j = 0; j < n - i - 1; j++)
        {
             if (temp->data > temp->next->data)
            {
                int x = temp->data;       
                temp->data = temp->next->data;
                temp->next->data = x;      
            }
            temp = temp->next;
        } 
    } 
} 
 
void createList (int data) 
{
  
    struct Node *newNode = malloc (sizeof (struct Node)); 
    newNode->next = NULL; 
    newNode->data = data; 
    if (head == NULL)   
    {     
        head = newNode;   
    } 
    else 
    {      
        struct Node *temp = head;    
        while (temp->next != NULL)
        {  
            temp = temp->next;
        }
        temp->next = newNode;
    }
} 
void displayList (struct Node *head) 
{
    while (head)
    {      
        printf ("%d ", head->data);      
        head = head->next;    
    }
}
int main () 
{ 
    int n; 
    printf("\n Enter the number of nodes : ");
    scanf ("%d", &n);
    head = NULL;
    printf("\n Enter the data : ");
    for (int i = 0; i < n; i++)
    {     
        int data;     
        scanf ("%d", &data);     
        createList (data);
    } 
    printf("\n The list is : ");
    displayList (head); 
    int size = len (head);
    sortList (size); 
    deleteDuplicates (head); 
    printf("\n List after deleting the duplicate elements : ");
    displayList (head); 
    return 0;
}


