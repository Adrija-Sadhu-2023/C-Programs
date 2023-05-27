/* WAP to represent a sparse matrix in 3-tuple method.*/
#include<stdio.h>
int main()
{
    int m,n,mat[5][4],i,j;
    printf("\n Enter the no. of rows & columns of the sparse matrix : ");
    scanf("%d%d",&m,&n);

    printf("\n Enter the elements : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&mat[i][j]);
    }

    int nzero=0;

    printf("\n The sparse matrix is : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d",mat[i][j]);
            if(mat[i][j]!=0)
            nzero++;
        }
        printf("\n");
    }

    int r,k=1;
    r=nzero+1;
    int tuplet[r][3];
    tuplet[0][0]=m;
    tuplet[0][1]=n;
    tuplet[0][2]=nzero;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat[i][j]!=0)
            {
                tuplet[k][0]=i;
                tuplet[k][1]=j;
                tuplet[k][2]=mat[i][j];
                k++;
            }
        }
    }

    printf("\n Tuplet : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<3;j++)
        printf(" %d",tuplet[i][j]);
        printf("\n");
    } 
}