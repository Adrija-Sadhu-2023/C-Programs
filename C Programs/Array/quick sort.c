/*Implement quick sort*/
#include <stdio.h>
void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    printf("%d ", arr[i]);
}
int partition(int arr[], int low, int high)
{
    int pivot;
    pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
    
}
void quickSort(int arr[], int low, int high)
{
    int partitionIndex;
    if(low<high)
    {
        partitionIndex = partition(arr,low, high);
        quickSort(arr, low,partitionIndex-1);
        quickSort(arr, partitionIndex+1,high);
    }
}
int main() 
{
    int n;
    printf("\n Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\n Enter the element in the array: ");
    for(int i = 0; i<n; i++)
    scanf("%d", &arr[i]);

    printf("\n Before sorting : ");
    printArray(arr, n);
    quickSort(arr, 0, n);

    printf("\n");

    printf("\n After sorting : ");
    printArray(arr, n);

    return 0;

}