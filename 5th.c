#include<stdio.h>
#include<conio.h>
void swap(int &a,int &b)
{
   int temp=a;
   a=b;
   b=temp;
}
 main()
{
    int t1,i,j,flag;
    printf("How many number of terms in first polynomial ?  \t ");
    {
        scanf("%d",&t1);
    }

    int array1[4][t1];
    printf("enter coefficient of each term: ");
    for(i=0;i<t1;i++)
    {
        scanf("%d",&array1[0][i]);
    }
    printf("enter the power of x for each term :");
    for(i=0;i<t1;i++)
    {
        scanf("%d",&array1[1][i]);
    }
    printf("enter the power of y for each term :");
    for(i=0;i<t1;i++)
    {
        scanf("%d",&array1[2][i]);
    }
    printf("enter the power of z for each term:");
    for(i=0;i<t1;i++)
    {
        scanf("%d",&array1[3][i]);
    }
    printf("The entered polynomial is \n\t\t p(X,Y,Z) = ");
    for(i=0;i<t1;i++)
        {
            printf("%d X^%d Y^%d Z^%d",array1[0][i],array1[1][i],array1[2][i],array1[3][i]);

            if( i!=(t1-1) )
                printf("  +  ");
        }

    int t2;
    printf("\n\nenter number of terms in second polynomial:");
    {
    scanf("%d",&t2);
    }
    int array2[4][t2];
    printf("enter coefficient of every term:");
    for(i=0;i<t2;i++)
    {
        scanf("%d",&array2[0][i]);
    }
    printf("enter the power of x for each term:");
    for(i=0;i<t2;i++)
    {
        scanf("%d",&array2[1][i]);
    }
    printf("enter the power of y for each term :");
    for(i=0;i<t2;i++)
    {
          scanf("%d",&array2[2][i]);
    }
    printf("enter the power of z for each term :");
    for(i=0;i<t2;i++)
    {
        scanf("%d",&array2[3][i]);
    }
    printf("The entered second polynomial is \n\t\t g(X,Y,Z) = ");
    for(i=0;i<t2;i++)
        {
            printf("%d X^%d Y^%d Z^%d",array2[0][i],array2[1][i],array2[2][i],array2[3][i]);

            if( i!=(t2-1) )
                printf("  +  ");
        }

    int t3 = t1+t2;
    int array3[4][t3],k=0;
    for(i=0;i<t1;i++)
    {
        flag=0;
        for(j=0;j<t2;j++)
        {
            if(array1[1][i]==array2[1][j] && array1[2][i]==array2[2][j] && array1[3][i]==array2[3][j] )
            {
            array3[0][k]=array1[0][i]+array2[0][j];
            array3[1][k]=array1[1][i];
            array3[2][k]=array1[2][i];
            array3[3][k]=array1[3][i];
            k++;
            flag=1;
            array2[0][j]=0;
            break;
            }
        }
        if(flag==0)
        {
            array3[0][k]=array1[0][i];
            array3[1][k]=array1[1][i];
            array3[2][k]=array1[2][i];
            array3[3][k]=array1[3][i];
            k++;
        }
    }
    for(i=0;i<t2;i++)
    {
        if(array2[0][i]!= 0)
        {
            array3[0][k]=array2[0][i];
            array3[1][k]=array2[1][i];
            array3[2][k]=array2[2][i];
            array3[3][k]=array2[3][i];
            k++;
        }
    }
    int temp=0;
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(array3[1][i]<array3[1][j])
            {
                swap( array3[0][i],array3[0][j] );
                swap( array3[1][i],array3[1][j] );
                swap( array3[2][i],array3[2][j] );
                swap( array3[3][i],array3[3][j] );
            }
            else if(array3[1][i]==array3[1][j])
            {
                if(array3[2][i]<array3[2][j])
                {
                    swap( array3[0][i],array3[0][j] );
                    swap( array3[1][i],array3[1][j] );
                    swap( array3[2][i],array3[2][j] );
                    swap( array3[3][i],array3[3][j] );

                }
                else if(array3[2][i]==array3[2][j])
                {
                    if(array3[3][i]<array3[3][j])
                    {
                        swap( array3[0][i],array3[0][j] );
                        swap( array3[1][i],array3[1][j] );
                        swap( array3[2][i],array3[2][j] );
                        swap( array3[3][i],array3[3][j] );
                    }
                }
            }
        }
    }


    printf("\n\n the addition of two  polynomial is \n h(X,Y,Z) =    ");
    for(i=0;i<k;i++)
        {
            printf("%d X^%d Y^%d Z^%d",array3[0][i],array3[1][i],array3[2][i],array3[3][i]);

            if( i!=(k-1) )
            printf("  +  ");
        }
}
