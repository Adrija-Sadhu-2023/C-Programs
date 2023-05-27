/*Assume that an array contains both even and odd numbers. Write a program to delete only 
the odd numbers and display the array.*/
#include<stdio.h>
int main()
{
    int n,i,j,a[10],c[10],k=0;

    printf("\n Enter the no. of elements : ");
    scanf("%d",&n);

    printf("\n Enter the elements : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            c[k]=a[i];
            k++;
        }
    }
    printf("\n The array after deleting the odd elements : ");
    for(i=0;i<k;i++)
    printf(" %d",c[i]);
}