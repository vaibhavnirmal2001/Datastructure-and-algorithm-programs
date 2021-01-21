#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
 main()
{
 int term1,i,j,flag;
 printf("enter number of terms in first polynomial=") ;
 scanf("%d",&term1);
 int arr1[4][term1];
 printf("enter coefficient of every term= ");
 for(i=0;i<term1;i++)
 scanf("%d",&arr1[0][i]);
 printf("enter the power of x for each term= ");
 for(i=0;i<term1;i++)
 scanf("%d",&arr1[1][i]);
 printf("enter the power of y for each term= ");
 for(i=0;i<term1;i++)
 scanf("%d",&arr1[2][i]);
 printf("enter the power of z for each term= ");
 for(i=0;i<term1;i++)
 scanf("%d",&arr1[3][i]);
 printf("The entered polynomial is \n\t\t p(X,Y,Z) = ");
 for(i=0;i<term1;i++)
 {
printf("%d X%d Y%d Z%d",arr1[0][i],arr1[1][i],arr1[2][i],arr1[3][i]);
 if( i!=(term1-1) )
 printf(" + ");
 }
 int term2;
 printf("\n\nenter number of terms in second polynomial= ") ;
 scanf("%d",&term2);
 int arr2[4][term2];
 printf("enter coefficient of every term= ");
 for(i=0;i<term2;i++)
 scanf("%d",&arr2[0][i]);
 printf("enter the power of x for each term= ");
 for(i=0;i<term2;i++)
 scanf("%d",&arr2[1][i]);
 printf("enter the power of y for each term=");
 for(i=0;i<term2;i++)
 scanf("%d",&arr2[2][i]);
 printf("enter the power of z for each term=");
 for(i=0;i<term2;i++)
 scanf("%d",&arr2[3][i]);
 printf("The entered polynomial is \n\t\t g(X,Y,Z) = ");
 for(i=0;i<term2;i++)
 {
 printf("%d X%d Y%d Z%d",arr2[0][i],arr2[1][i],arr2[2][i],arr2[3][i]);
 if( i!=(term2-1) )
 printf(" + ");
 }
 int term3 = term1+term2;
 int arr3[4][term3],k=0;
 for(i=0;i<term1;i++)
 {
 flag=0;
 for(j=0;j<term2;j++)
 {
 if(arr1[1][i]==arr2[1][j] && arr1[2][i]==arr2[2][j] && arr1[3][i]==arr2[3][j] )
 {
 arr3[0][k]=arr1[0][i]+arr2[0][j];
 arr3[1][k]=arr1[1][i];
 arr3[2][k]=arr1[2][i];
 arr3[3][k]=arr1[3][i];
 k++;
 flag=1;
 arr2[0][j]=0;
 break;
 }
 }
 if(flag==0)
 {
 arr3[0][k]=arr1[0][i];
 arr3[1][k]=arr1[1][i];
 arr3[2][k]=arr1[2][i];
 arr3[3][k]=arr1[3][i];
 k++;
 }
 }
 for(i=0;i<term2;i++)
 {
 if(arr2[0][i] != 0)
 {
 arr3[0][k]=arr2[0][i];
 arr3[1][k]=arr2[1][i];
 arr3[2][k]=arr2[2][i];
 arr3[3][k]=arr2[3][i];
 k++;
 }
 }
 int temp=0;
 for(i=0;i<k-1;i++)
 {
 for(j=i+1;j<k;j++)
 {
 if(arr3[1][i]<arr3[1][j]) //checking power of X
 {
 swap( arr3[0][i],arr3[0][j] );
 swap( arr3[1][i],arr3[1][j] );
 swap( arr3[2][i],arr3[2][j] );
 swap( arr3[3][i],arr3[3][j] );
 }
 else if(arr3[1][i]==arr3[1][j]) //if power of X is same
 {
 if(arr3[2][i]<arr3[2][j]) //checking power of Y
 {
 swap( arr3[0][i],arr3[0][j] );
 swap( arr3[1][i],arr3[1][j] );
swap( arr3[2][i],arr3[2][j] );
 swap( arr3[3][i],arr3[3][j] );
 }
 else if(arr3[2][i]==arr3[2][j]) //if power of Y is same
 {
 if(arr3[3][i]<arr3[3][j]) //checking power of Z
 {
 swap( arr3[0][i],arr3[0][j] );
 swap( arr3[1][i],arr3[1][j] );
 swap( arr3[2][i],arr3[2][j] );
 swap( arr3[3][i],arr3[3][j] );
 }
 }
 }
 }
 }
 printf("\n\nThe resultant polynomial contains \n h(X,Y,Z) = ");
 for(i=0;i<k;i++)
 {
 printf("%d X%d Y%d Z%d",arr3[0][i],arr3[1][i],arr3[2][i],arr3[3][i]);
 if( i!=(k-1) )
 printf(" + ");
 }
}
