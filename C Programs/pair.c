#include<stdio.h>
void pair(int a[],int b[],int m,int n,int x)
{
    int i,j;
    printf("\n Pair whose sum is %d : ",x);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]+b[j]==x)
            printf(" %d and %d",a[i],b[j]);
        }
    } 
 }
int main()
{
    int m,n,i,x;
    printf("\n Enter the size of the 2 arrays : ");
    scanf("%d%d",&m,&n);
    int a[m],b[n];
    printf("\n Enter the elements of the 1st array in sorted order : ");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("\n Enter the elements of the 2nd array in sorted order : ");
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    printf("\n Enter the number : ");
    scanf("%d",&x);
    pair(a,b,m,n,x);
}