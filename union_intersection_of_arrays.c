#include<stdio.h>

void uni(int a[],int b[],int m,int n) {
    int size=m+n;
    int i,c[size],j,k;
    for(i=0;i<m;i++)
    c[i]=a[i];
    for(i=0;i<n;i++)
        c[m+i]=b[i];
    for(i=0;i<size;i++) {
        for(j=i+1;j<size;j++) {
            if(c[i]==c[j])
            {
                for(k=j;k<size;k++)
                c[k]=c[k+1];
                size--;
            }
        }
    }
    for(i=0;i<size;i++)
    printf(" %d",c[i]);
}
void inter(int a[],int b[],int m,int n) {
     int i,j,k=0,c[m+n];
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            if(a[i]==b[j])
            {
                c[k]=b[j];
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    printf(" %d",c[i]);
}
int main()
{
    int m,n,i;
    printf("\n Enter the size of the 2 arrays : ");
    scanf("%d%d",&m,&n);
    int a[m],b[n];
    printf("\n Enter the elements of the 1st array in sorted order : ");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("\n Enter the elements of the 2nd array in sorted order : ");
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    printf("\n Union of the two arrays is : ");
    uni(a,b,m,n);
    printf("\n Intersection of the two arrays is : ");
    inter(a,b,m,n);
    return 0;
}