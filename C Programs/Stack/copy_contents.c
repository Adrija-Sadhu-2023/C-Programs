/*Copy the contents of a stack to another stack in the same order without using 
any additional data structures.*/
#include <stdio.h> 
#include <stdlib.h> 
#define size 100 
int top = -1, c = 0, stack1[size], stack2[size];
void push ()
{
    int data;
    printf ("Enter the element:");
    scanf ("%d", &data);
    if (top == size - 1)
    {
        printf ("Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack1[top] = data;
    }
}

void pop ()
{
    if (top == -1)
    {
        printf ("Underflow");
        return;
    }
    else
    {
        printf ("The pop element is=%d", stack1[top]);
        top = top - 1;  
    }
}

void display () 
{
    int n;
    printf ("Enter 1 for 1st stack and 2 for Copied stack:"); 
    scanf ("%d", &n); 
    
    if (n == 1)
    {   
        int i;   
        if (top == -1)
        {	  
            printf ("Stack is Empty");	  
            return;
        }
        else	
        {	  
            printf ("1st Stack:");	  
            for (i = top; i >= 0; i--)
            printf ("%d ", stack1[i]);
        }
    } 
    else    
    {      
        int i;     
        if (top == -1)
        {
            printf ("Stack is Empty"); 
            return;
        }
        else	
        {	  
            printf ("2nd Stack:");	  
            for (i = top; i >= 0; i--)
            printf ("%d ", stack2[i]);
        }
    }
}
void copy () 
{
    int i, c1 = 0; 
    for (i = top; i >= 0; i--)
    {      
        stack2[c1] = stack1[i];     
        c1++;
    }
}
void swap () 
{
    int t, c = top, m = 0; 
    for (int i = 0; i <= top / 2; i++)
    {      
        if (m == c)	
        return;
        int t = stack2[c];
        stack2[c] = stack2[m];
        stack2[m] = t;  
        m++;
        c--;
    }
} 
void main () 
{
    int choice; 
    while (1)
    {      
        printf ("\n1-PUSH\n2-POP\n3-DISPLAY\n4-COPY\n5-EXIT\n");     
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
            copy ();
            swap ();
            printf ("Elements have been copied into the 2nd stack");
            break;
                
            case 5:
            exit (1);
                
            default:
            printf ("Enter valid choice");
        }
    }
}
  
