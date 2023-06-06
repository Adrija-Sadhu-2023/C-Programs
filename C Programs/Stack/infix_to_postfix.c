/*Write a program to convert a given INFIX expression to POSTFIX expression 
and evaluate the POSTFIX expression.*/
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
#define MAX 20 
char infix[MAX],postfix[MAX]; 
int stack[MAX],top;

int isempty ()
{
    if (top == -1)
    return 1;

    else
    return 0;
}

void PUSH (int symbol)
{
    if (top > MAX)
    {
        printf ("Overflow");
        exit (1);
    }
    stack[++top] = symbol;
}

int POP ()
{
    if (isempty ())
    {
        printf ("Underflow");
        exit (1);
    }
    return (stack[top--]);
}

int Priority (char symbol)
{
    switch (symbol)
    {
        case '(':
        return 0;
        break;

        case '+':
        case '-':
        return 1;

        case '*':
        case '/':
        case '%':
        return 2;

        case '^':
        return 3;

        default:
        return 0;
        break;
    }
}
void infixtopostfix ()
{
    int i, p = 0;
    char next, symbol;
    for (i = 0; i < strlen (infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
            
            case '(':   
            PUSH (symbol);
            break;
                
            case ')':
            while ((next = POP ()) != '(')
            postfix[p++] = next;
            break;
                
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            while (!isempty () && Priority (stack[top]) >= Priority (symbol))
            postfix[p++] = POP ();
            PUSH (symbol);
            break;

            default:    
            postfix[p++] = symbol;
            break;
        }
    }
    while (!isempty ())   
    {
        postfix[p++] = POP ();
    }
    postfix[p] = '\0';
}
int eval_post () 
{
    int a, b, tmp, result, i;   
    for (i = 0; i < strlen (postfix); i++)
    {    
        if (postfix[i] <= 'q' && postfix[i] >= '0')  
        PUSH (postfix[i] - '0'); 
        else
        {
            a = POP ();   
            b = POP ();   
            switch (postfix[i])
            {  
                case '+':           
                tmp = b + a;
                break;
                        
                case '-':
                tmp = b - a;
                break;
                        
                case '*':
                tmp = b * a;
                break;
                        
                case '/':
                tmp = b / a;
                break;
                        
                case '%':
                tmp = b % a;
                break;
                        
                case '^':     
                tmp = pow (b, a);
            }
            PUSH (tmp);
        }
    }
    result = POP ();
    return result;
}
int main () 
{ 
    int value;
    top = -1;
    printf ("\nEnter the infix expression: ");
    gets (infix);
    infixtopostfix ();
    printf ("\nPostfix Expression : %s\n", postfix);
    value = eval_post ();
    printf ("\nEvaluated Value : %d", value);
} 
