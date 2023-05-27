/* Assume that there are two sparse matrices. Convert these two matrices into their triplet 
format, then add these two triplet matrices.*/
#include<stdio.h>
int main()
{
    int m,n,o,p,mat1[5][4],mat2[4][5],i,j,sum[20][30];

    printf("\n Enter the no. of rows & columns of the 1st sparse matrix : ");
    scanf("%d%d",&m,&n);

    printf("\n Enter the no. of rows & columns of the 2nd sparse matrix : ");
    scanf("%d%d",&o,&p);

    printf("\n Enter the elements of the 1st sparse matrix : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&mat1[i][j]);
    }

    printf("\n Enter the elements of the 2nd sparse matrix : ");
    for(i=0;i<o;i++)
    {
        for(j=0;j<p;j++)
        scanf("%d",&mat2[i][j]);
    }

    int nz1=0,nz2=0;

    printf("\n 1st sparse matrix : \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %d",mat1[i][j]);
            if(mat1[i][j]!=0)
            nz1++;
        }
        printf("\n");
    }

    printf("\n 2nd sparse matrix : \n");
    for(i=0;i<o;i++)
    {
        for(j=0;j<p;j++)
        {
            printf(" %d",mat2[i][j]);
            if(mat2[i][j]!=0)
            nz2++;
        }
        printf("\n");
    }

    int r1,r2,k=1,l=1;
    r1=nz1+1;
    r2=nz2+1;
    int tuplet1[r1][3],tuplet2[r2][3];
    tuplet1[0][0]=m;
    tuplet1[0][1]=n;
    tuplet1[0][2]=nz1;
    tuplet2[0][0]=o;
    tuplet2[0][1]=p;
    tuplet2[0][2]=nz2;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(mat1[i][j]!=0)
            {
                tuplet1[k][0]=i;
                tuplet1[k][1]=j;
                tuplet1[k][2]=mat1[i][j];
                k++;
            }
        }
    }

    for(i=0;i<o;i++)
    {
        for(j=0;j<p;j++)
        {
            if(mat2[i][j]!=0)
            {
                tuplet2[l][0]=i;
                tuplet2[l][1]=j;
                tuplet2[l][2]=mat2[i][j];
                l++;
            }
        }
    }

    printf("\n Tuplet 1 : \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<3;j++)
        printf(" %d",tuplet1[i][j]);
        printf("\n");
    }

    printf("\n Tuplet 2 : \n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<3;j++)
        printf(" %d",tuplet2[i][j]);
        printf("\n");
    }

    if(nz1!=nz2)
    {
        printf("\n Matrix can not be added : ");
        return 0;
    }

    else
    {
        for(i=1;i<r2;i++)
        {
            for(j=0;j<3;j++)
            sum[i][j]=tuplet1[i][j]+tuplet2[i][j];
        }
        printf("\n Addition of the tuplets : \n");
        for(i=1;i<r2;i++)
        {
            for(j=0;j<3;j++)
            printf(" %d",sum[i][j]);
            printf("\n");
        }
    } 
}