/*Assume that there is a stack of n elements, 
write a program to reverse the elements of the stack using an extra stack. 
(Without violating the LIFO concept)*/
#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h> 
struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};

struct stack *createStack ()
{
    struct stack *s;
    s = (struct stack *) malloc (sizeof (struct stack));
    s->top = NULL;
    return s;
}

void push (struct stack *stk, int data)
{
    struct node *temp;
    temp = (struct node *) malloc (sizeof (struct node));
    if (!temp)
    {
        printf ("\nStack/Heap overflow");
        return;
    }
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
}

int isEmpty (struct stack *stk)
{
    return stk->top == NULL;
}

int pop (struct stack *stk)
{
    int data;
    struct node *temp;
    if (isEmpty (stk))
        return INT_MIN;
    temp = stk->top;
    stk->top = stk->top->next;
    data = temp->data;
    free (temp);
    return data;
}

void display (struct stack *stk)
{
    struct node *t;
    t = stk->top;
    if (isEmpty (stk))
        return;
    while (t != NULL)
    {
        printf ("%d", t->data);
        t = t->next;
    }
}

int stk_size (struct stack *stk) 
{
    int count = 0;   
    struct node *temp;
    if (isEmpty (stk))
    {    
        return 0;   
    }
    temp = stk->top;
    while (temp->next != NULL)
    { 
        count++;       
        temp = temp->next;
    }
    return count;
}

void transfer (struct stack *a, struct stack *b, int n) 
{
    for (int i = 0; i < n; i++)       
    {
        int temp = a->top->data;
        pop (a);
        push (b, temp);
    }
} 
void  reverse_stk (struct stack *stk, int n) 
{
    struct stack *q = createStack ();   
    int t;
    if (isEmpty (stk))
    return;
    
    for (int i = 0; i < n - 1; i++)
    {
        t = stk->top->data;       
        pop (stk);
        transfer (stk, q, n - i - 1);
        push (stk, t);
        transfer (q, stk, n - i - 1);
    } 
    display (stk);
} 
int main () 
{
    int i = 0, size;   
    struct stack *stk = createStack ();
    for (i = 0; i < 10; i++)
    {
        push (stk, i);   
    }
    printf("\n The stack is : ");
    display (stk);
    size = stk_size (stk);
    printf("\n The reversed stack is : ");
    reverse_stk (stk, size);
}


