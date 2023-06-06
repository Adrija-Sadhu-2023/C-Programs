/*Implement selection sort*/
#include<stdio.h>
void selection_sort (int arr[], int n)
{
    int i, j, tmp;
    printf ("\n Before Sorting: ");
    for (i = 0; i < n; i++)
    {
        printf (" %d ", arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf ("\n After Sorting: ");
    for (i = 0; i < n; i++)
    {
        printf (" %d ", arr[i]);
    }
}

int main ()
{
    int n, i, ch;
    printf ("Enter size of array: ");
    scanf ("%d", &n);
    int arr[n];
    printf ("Enter elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &arr[i]);
    }
    selection_sort (arr, n);
    return 0;
}
