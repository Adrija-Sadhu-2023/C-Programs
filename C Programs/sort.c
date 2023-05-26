/*
Sort the elements of an array both in ascending and descending order
*/
#include<stdio.h>
void ascending(int arr[],int m)
{
    int i,j,temp;

    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

 printf("\n Ascending Order : ");
 for(i=0;i<m;i++)
 printf(" %d",arr[i]);
}

void descending(int arr[],int m)
{
    int i,j,temp;
    
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(arr[j]>arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    printf("\n Descending Order : ");
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

    ascending(arr,m);
    
    descending(arr,m);
}