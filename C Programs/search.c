/*
 Search an element in an array and count the number of times that element is present.
*/
#include<stdio.h>
void search(int arr[],int m,int a)
{
    int i,count=0;
    for(i=0;i<m;i++)
    {
        if(arr[i]==a)
        {
            printf("\n %d is present at position : %d",a,(i+1));
            count++;
        }
    }
    
    printf("\n Number of times %d is present = %d",a,count);
}
int main()
{
    int i,m,a;
    printf("\n Enter the size : ");
    scanf("%d",&m);

    int arr[m];

    printf("\n Enter the elements : ");
    for(i=0;i<m;i++)
    scanf("%d",&arr[i]);

    printf("\n The element to be searched : ");
    scanf("%d",&a);

    search(arr,m,a);
}
