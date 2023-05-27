/* Given two sorted arrays A and B. Array A is full and array B is partially full and the number of 
empty slots are just enough to accommodate all elements of array A. Write a program to merge 
the two sorted arrays to fill the array B without using the third array.*/
#include<stdio.h>
int main()
{
    int m,n,a[10],b[10],i,k,j,temp;

    printf("\n Enter the no. of elements in the 2 arrays : ");
    scanf("%d%d",&m,&n);

    printf("\n Enter the elements of the 1st array : ");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);

    k=n-m;

    printf("\n Enter %d elemnts in 2nd array : ",k);
    for(i=0;i<k;i++)
    scanf("%d",&b[i]);

    for(int i=0;i<n;i++)
    b[k+i]=a[i];

    printf("\n Merged array : ");
    for(int i=0;i<n;i++)
    printf(" %d",b[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[i]>b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    
    printf("\n\n Sorted merged array : ");
    for(i=0;i<n;i++)
    printf(" %d",b[i]);
}