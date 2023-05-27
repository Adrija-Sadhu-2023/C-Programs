/*
 Given three arrays sorted in non-decreasing order, print all common elements in these arrays
*/
#include<stdio.h>
void common(int a[],int b[],int c[],int m,int n,int o)
{
    int i,j,k,flag=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<o;k++)
            {
                if(a[i]==b[j] && b[j]==c[k])
                {
                    printf(" %d",a[i]);
                    flag=1;
                }
            }
        }
    } 
    if(flag==0)
    printf("\n No common elements ");
}
int main()
{
    int m,n,o,i,x;

    printf("\n Enter the size of the 3 arrays : ");
    scanf("%d%d%d",&m,&n,&o);

    int a[m],b[n],c[o];

    printf("\n Enter the elements of the 1st array in non-decreasing order : ");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);

    printf("\n Enter the elements of the 2nd array in non-decreasing order : ");
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);

    printf("\n Enter the elements of the 1st array in non-decreasing order : ");
    for(i=0;i<o;i++)
    scanf("%d",&c[i]);

    printf("\n Common Elements are : ");
    common(a,b,c,m,n,o);
}