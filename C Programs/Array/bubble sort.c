/*Implement bubble sort*/
#include<stdio.h>
void bubble_sort(int arr[],int n)
{
    int i,j,tmp;
    printf("\n Before Sorting: ");
    for(i=0;i<n;i++)
    printf(" %d ",arr[i]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
        printf("\n After Sorting: ");
        for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
}
int main()
{
    int n,i,ch;
    printf("\n Enter size of array: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\n Enter elements of array: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    bubble_sort(arr,n);
    return 0;
}