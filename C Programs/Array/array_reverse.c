/*
Reverse the elements of an array without using a 2nd array.
*/
#include<stdio.h>
void reverse(int arr[],int m)
{
    int i,temp,j;

    for(i=0;i<m/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[m-1-i];
        arr[m-1-i]=temp;
    }
    printf("\n Reverse Order : ");
    for(i=0;i<m;i++)
    printf(" %d",arr[i]);
}
int main()
{
    int i,m;
    printf("\n Enter the size : ");
    scanf("%d",&m);

    int arr[m];

    printf("\n Enter the elements : ");
    for(i=0;i<m;i++)
    scanf("%d",&arr[i]);

    reverse(arr,m);
}
