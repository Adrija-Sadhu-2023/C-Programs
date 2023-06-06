/*Merge two sorted stacks S1 & S2 by using only push() and pop() functions 
and without taking any additional data structures. 
The final merge list to be stored in S1.*/
#define size1 20 
#define size2 10 
#include<stdio.h> 
#include<stdlib.h> 
void display1 ();
void display2 ();
void display_merge (int);
int top1 = -1, top2 = -1;
int stack1[size1], stack2[size2];

void push1(int n)
{
    int data1;
    if (top1 == n - 1)
    {
        printf ("\n Overflow");
        return;
    }
    else
    {
        printf ("\n Enter the elements of the 1st stack : ");
        for (int i = 0; i < n; i++)
        {
        scanf ("%d", &data1);
        top1 = top1 + 1;
        stack1[top1] = data1;
    }
    }
    printf ("\n Stack 1 : ");
    display1 ();
} 
void push2(int m)
{
    int data2;
    if (top2 == m - 1)
    {
        printf ("\n Overflow");
        return; 
    }
    else    
    {      
        printf ("\n Enter the elements of the 2nd stack : ");     
        for (int i = 0; i < m; i++)
        {	  
            scanf ("%d", &data2);	  
            top2 = top2 + 1;
            stack2[top2] = data2;
        }
    } 
    printf ("\n Stack 2 : "); 
    display2 ();
} 
void display1 () 
{ 
    int i; 
    if (top1 == -1)
    {      
        printf ("\n Stack is empty");     
        return;
    }
    else    
    {      
        for (i = top1; i >= 0; i--)	
        printf (" %d", stack1[i]);
    }
}
void display2 () 
{
    int i; 
    if (top2 == -1)
    {
        printf ("\n Stack is empty");      
        return;
    } 
    else    
    {      
        for (i = top2; i >= 0; i--)	
        printf (" %d", stack2[i]);
    }
}
void merge (int stack1[], int n, int m,int stack2[]) 
{
    int k; 
    k = n + m - 1;
    for (int i = 0; i < k; i++)   
    stack1[n + i] = stack2[i];
    display_merge (k);
} 
void display_merge (int k) 
{
    printf ("\n Merged Stack : ");
    for (int i = k; i >= 0; i--)
    printf (" %d", stack1[i]);
} 

int main () 
{
    int n,m; 
    printf ("\n Enter n : ");
    scanf ("%d", &n);
    push1(n);
    printf ("\n Enter m : ");
    scanf("%d", &m);
    push2(m);
    merge (stack1,n,m,stack2);
} 
