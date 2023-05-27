/*Given an array of positive integers of size n, find the minimum repeating number and its 
frequency in this array.*/
#include <stdio.h>
int main()
{
    int n, i, j, c, min_freq, min_no;
    printf("Enter the size of the array : "); scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array : "); for (i = 0; i < n; i++)
    scanf("%d", &a[i]); 
    min_freq = n;
    for (i = 0; i < n; i++)
    {
        c = 0;
            for (j = 0; j < n; j++)
            {
                if (a[j] == a[i])
                c++;
            }
            if (min_freq > c)
            {
                min_no = a[i]; 
                min_freq = c;
            }
    }
    printf("The minimum repeating number is %d and its frquency is %d times.", min_no, min_freq);
}