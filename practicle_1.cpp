#include <stdio.h>
#include<conio.h>
 void linear(void);
 void binary(void);
 void fibo(void);
 char sort(char array[10][10],int size);

void main()
{ int choice; while(1)
   {
        printf("Menu:");
        printf("select any one :\n  1.Linear search \n  2.Binary search \n  3.Fibonacci search \n  4.Exit \n");
        scanf("%d",&choice);

    if (choice==1)
                 {  linear();
                 }
          else if(choice==2){
                             binary();
                             }
          else if(choice==3)  {
                             fibo();
                              }
          else  { break;
                }
         printf("\n \n");
    }
 }



void linear(void)
{
     int size,i,comp=0;
     char array[10][10],element[10] ;
     printf("Linear search \n  enter number of strings  ");
        {
             scanf("%d",&size);
         }
    printf("Enter the elements of string array :-");
    for(i=0;i<size;i++)
         {
              scanf("%s",& array[i]);
         }
    printf("Enter the key to be search in string array ");
         {
             scanf("%s",&element);
          }
for(i=0;i<size;i++)
  {
     comp++;
    if(strcmp(array[i],element)==0)

        {
            printf("string %s is found at the index value %d  \n number of comp required are %d \n  ",element,i,comp);

       if(comp==1)
               printf ("this is best case");

        else if( comp==size )
               printf("this is worst case");
         else
                printf("this is average case");

                break;
        }

    }
          if (i==(size))
           {
               printf("string not present in array");
               }
               else{printf("\n");}
    }



 void binary(void)
{
     int size,i,low=0,high,mid,comp=0;
     char array[10][10],element[10];
           printf("Binary search \n enter number of strings");
                {
                 scanf("%d",&size);
                }

            printf("Enter elements of string array");
                  for(i=0;i<size;i++)
                {
                      scanf("%s",& array[i]);
                }

   sort(array,size);
            printf("sorted string are:- \n ");
            for(i=0;i<size;i++)
            {
             printf("%s ", array[i]);
            }

printf("\Enter the key to be search in string array ");

              scanf("%s",&element);
     high=size-1;
    while(low<=high)
    {
       comp++;
       mid=(low+high)/2;

    if( strcmp(array[mid],element)==0 )
        {
            printf("string %s is found at index value %d after %d comp \n",element,mid,comp);
                if(comp==1)
                {
                  printf("this is best case");
                }
                else if( comp>log2(size) )
                        {
                            printf("this is worst case");
                        }
                  else
                  {
                          printf("this is average case");
                    }
                   break;
        }


        else if( strcmp(array[mid],element)<0 )
           {
             low=mid+1;
           }
        else if( strcmp(array[mid],element)>0 )
           {
             high=mid-1;
           }
    }

     if(low>high)
      {
           printf("string not present in array");
      }
}


void fibo(void)
{
    int size,i,offset,m,m1=1,m2=0,comp=0;
    char array[10][10],element[10];

      printf(" fibonacci search :-\n   enter number of strings:-");
      scanf("%d",&size);

      printf("Enter the elements of string array :-");
        for(i=0;i<size;i++)
          {
              scanf("%s",&array[i]);
          }

    sort(array,size);
     printf("sorted strings are:- ");
       for(i=0;i<size;i++)
        {
          printf("%s ",array[i]);
        }

    printf("\n Enter the key to be search in string array  ");
    scanf("%s",&element);

    m=m1+m2;
    while(m<size)
    {
             m2=m1;
             m1=m;
             m=m1 + m2;
    }
    offset=-1;
      while(m>1)
    {
       comp++;
     if((offset+m2)<(size-1))
        {
           i=offset+m2;
        }
     else
        {
          i=size-1;
        }
        if( strcmp(array[i],element)==0 )
       {
            printf("string %s is found at index value %d after %d comp \n",element,i,comp);             if(comp==1)
            printf("this is best case");
            else if( comp>log2(size) )
               {
                 printf("this is worst case");
               }
         else
               {
                 printf("this is average case");             break;
               }
               break;
       }

       else if( strcmp(array[i],element)>0 )
       {
             m=m2;
             m1=m1-m2;
             m2=m-m1;
       }
       else if (strcmp(array[i],element)<0 )

       {
           m=m1;
           m1=m2;
           m2=m-m1;
           offset=i;
       }
         else
         {
             printf("string not found");
         }
    }
}


char sort(char array[10][10],int size)
{
   int i,j;
   char temp[10];
   for(i=0;i<size-1;i++)
      {
        for(j=i+1;j<size;j++)
           {
               if( strcmp(array[i],array[j])>0 )
                      {
                            strcpy(temp,array[i]);
                            strcpy(array[i],array[j]);
                            strcpy(array[j],temp);
                      }
           }
      }
}
