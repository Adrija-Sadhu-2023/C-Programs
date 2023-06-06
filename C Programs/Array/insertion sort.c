/*Implement insertion sort*/
#include<stdio.h>
void insertion_sort(int arr[],int n)
{
    int i,j,k;
    printf("\n Before Sorting: ");
    for(i=0;i<n;i++)
    printf(" %d ",arr[i]);

    for(i=0;i<n;i++)
    {
        k=arr[i];
        for (j = i-1; j >= 0 && k<arr[j]; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
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
    
    insertion_sort(arr,n);
    return 0;
}