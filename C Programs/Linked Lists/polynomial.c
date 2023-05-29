/*Implement polynomial addition and multiplication using linked list.*/
#include<stdio.h>
#include<stdlib.h>
struct node *insert (struct node *start, int co, int ex);
struct node
{
    int coef;
    int expo;
    struct node *link;
};
struct node *create (struct node *start)
{
    int i, n, ex, co;
    printf("\n Enter the no. of terms of the polynomial : ");
    scanf ("%d", &n);
    printf("\n Enter the coefficient and exponent : ");
    for (i = 1; i <= n; i++)
        {
        scanf ("%d%d", &co, &ex);
        start = insert (start, co, ex);
        }
    return start;
}

struct node *insert (struct node *start, int co, int ex)
{
    struct node *tmp, *q;
    tmp = (struct node *) malloc (sizeof (struct node));
    tmp->coef = co;
    tmp->expo = ex;
    if (start == NULL || ex > start->expo)
        {
        tmp->link = start;
        start = tmp;
        }
    else
        {
        q = start;
        while (q->link != NULL && q->link->expo >= ex)
        q = q->link;
        tmp->link = q->link;
        q->link = tmp;
        }
    return start;
}

void display (struct node *start)
{
    struct node *q = start;
    printf("\n The polynomial is : ");
    while (q != NULL)
        {
        printf ("%dx^%d", q->coef, q->expo);
        q = q->link;
        if (q != NULL)
        printf (" + ");
        else
        printf ("\n");
        }
}

void poly_add (struct node *p1, struct node *p2)
{
  struct node *start3;
  start3 = NULL;
  printf("\n Addition : ");
  while (p1 != NULL & p2 != NULL)
    {
      if (p1->expo > p2->expo)
	{
	  start3 = insert (start3, p1->coef, p1->expo);
	  p1 = p1->link;
	}
      else if (p2->expo > p1->expo)
	{
	  start3 = insert (start3, p2->coef, p2->expo);
	  p2 = p2->link;
	}
      else if (p1->expo == p2->expo)
	{
	  start3 = insert (start3, p1->coef + p2->coef, p1->expo);
	  p1 = p1->link;
	  p2 = p2->link;
	}
    }
  while (p1 != NULL)
    {
      start3 = insert (start3, p1->coef, p1->expo);
      p1 = p1->link;
    }
  while (p2 != NULL)
    {
      start3 = insert (start3, p2->coef, p2->expo);

      p2 = p2->link;
    }
  display (start3);
}

void poly_mult (struct node *p1, struct node *p2)
{
    struct node *start3 = NULL;
    struct node *p2_beg = p2;
    printf("\n Multiplication : ");
    while (p1 != NULL)
        {
        p2 = p2_beg;
        while (p2 != NULL)
        {
        start3 = insert (start3, p1->coef * p2->coef, p1->expo + p2->expo);
        p2 = p2->link;
        }
        p1 = p1->link;
        }
    display (start3);
}

int main ()
{
    struct node *start1 = NULL, *start2 = NULL;
    start1 = create (start1);
    display (start1);
    start2 = create (start2);
    display (start2);
    poly_add (start1, start2);
    poly_mult (start1, start2);
}
