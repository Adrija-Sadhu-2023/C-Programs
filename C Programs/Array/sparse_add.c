/* Write a program to add a square sparse matrix with the transpose of the same matrix, then 
represent the output matrix in three tuple method.*/
#include<stdio.h>
int main()
{
    int m,mat[5][4],i,j,mat1[4][5],output[10][10];

    printf("\n Enter the no. of rows & columns of the square sparse matrix : ");
    scanf("%d",&m);

    printf("\n Enter the elements : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        scanf("%d",&mat[i][j]);
    }

    printf("\n Matrix : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        printf(" %d",mat[i][j]);
        printf("\n");
    }

    printf("\n The transpose of the sparse matrix : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        mat1[i][j]=mat[j][i];
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        printf(" %d",mat1[i][j]);
        printf("\n");
    }

    printf("\n Addition of the square sparse matrix with the transpose : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        output[i][j]=mat[i][j]+mat1[i][j];
    }

    int nzero=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %d",output[i][j]);
            if(output[i][j]!=0)
            nzero++;
        }
        printf("\n");
    }

    int r,k=1;

    r=nzero+1;

    int tuplet[r][3];

    tuplet[0][0]=m;
    tuplet[0][1]=m;
    tuplet[0][2]=nzero;

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(output[i][j]!=0)
            {
                tuplet[k][0]=i;
                tuplet[k][1]=j;
                tuplet[k][2]=output[i][j];
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