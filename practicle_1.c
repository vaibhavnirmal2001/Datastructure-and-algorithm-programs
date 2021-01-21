#include <stdio.h> 
#include<conio.h>
 void linear(void); 
 void binary(void);
 void fibo(void);
 char sort(char arr[10][10],int size); 
 
void main() 
{ int choice; while(1) 
   {
        printf("Menu:");
        printf("choose any one :\n  1.Linear search \n  2.Binary search \n  3.Fibonacci search \n  4.Exit \n");  
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
 
 
 /*program for linier search*/
void linear(void) 
{  
     int size,i,comparison=0;  
     char arr[10][10],element[10] ;  
     printf("Linear search \n  enter number of strings  ");   
        {
             scanf("%d",&size); 
         }
    printf("Enter the strings :-");  
    for(i=0;i<size;i++)        
         {
              scanf("%s",&arr[i]); 
         }
    printf("which string you want to search?  ");  
         {
             scanf("%s",&element); 
          }
for(i=0;i<size;i++) 
  { 
     comparison++; 
    if(strcmp(arr[i],element)==0)
        
        {
            printf("string %s is found at the index value %d  \n number of comparisons required are %d \n  ",element,i,comparison);        
         
       if(comparison==1) 
               printf ("this is best case"); 
   
        else if( comparison==size )    
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



/* BINARY SEARCH PROGRAM*/
 void binary(void) 
{  
     int size,i,first=0,last,middle,comparison=0;
     char arr[10][10],element[10]; 
           printf("Binary search \n enter number of strings"); 
                {
                 scanf("%d",&size); 
                }
                 
            printf("Enter elements of string :- "); 
                  for(i=0;i<size;i++)     
                {
                      scanf("%s",&arr[i]); 
                }
     
   sort(arr,size); 
            printf("sorted string are:- \n ");   
            for(i=0;i<size;i++)         
            {
             printf("%s ",arr[i]); 
            }
 
printf("\n which string you want to search "); 

              scanf("%s",&element); 
     last=size-1;    
    while(first<=last) 
    { 
       comparison++; 
       middle=(first+last)/2;     
       
    if( strcmp(arr[middle],element)==0 ) 
        {
            printf("string %s is found at index value %d after %d comparison  \n",element,middle,comparison);         
                if(comparison==1) 
                {
                  printf("this is best case"); 
                } 
                else if( comparison>log2(size) )   
                        {
                            printf("this is worst case");
                        }
                  else 
                  {
                          printf("this is average case");      
                    }
                   break; 
        }
        
         
        else if( strcmp(arr[middle],element)<0 ) 
           {
             first=middle+1;
           }         
        else if( strcmp(arr[middle],element)>0 ) 
           {
             last=middle-1;
           }   
    }    
    
     if(first>last)    
      { 
           printf("string not present in array"); 
      }
} 

/* FIBONACCI SEARCH PROGRAM */
  
void fibo(void) 
{ 
    int size,i,offset,m,m1=1,m2=0,comparison=0;    
    char arr[10][10],element[10];   
    
      printf(" fibonacci search :-\n   enter number of strings:-"); 
      scanf("%d",&size); 
      
      printf("Enter the strings :-"); 
        for(i=0;i<size;i++)  
          {
              scanf("%s",&arr[i]); 
          }
             
    sort(arr,size);    
     printf("sorted strings are:- ");   
       for(i=0;i<size;i++)   
        {
          printf("%s ",arr[i]); 
        }
      
    printf("\n which string you want to search?  ");    
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
       comparison++; 
     if((offset+m2)<(size-1))
        {
           i=offset+m2;
        } 
     else
        {
          i=size-1; 
        }            
        if( strcmp(arr[i],element)==0 ) 
       {     
            printf("string %s is found at index value %d after %d comparison \n",element,i,comparison);             if(comparison==1) 
            printf("this is best case");  
            else if( comparison>log2(size) )   
               {
                 printf("this is worst case"); 
               }
         else
               { 
                 printf("this is average case");             break; 
               }
       }
         
       else if( strcmp(arr[i],element)>0 ) 
       {  
             m=m2;    
             m1=m1-m2;     
             m2=m-m1; 
       } 
       else if (strcmp(arr[i],element)<0 ) 
       
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
/*Sorting of string array*/
 
char sort(char arr[10][10],int size) 
{ 
   int i,j;
   char temp[10];       //array to copy the string Temporary 
   for(i=0;i<size-1;i++)  
      {
        for(j=i+1;j<size;j++) 
           { 
               if( strcmp(arr[i],arr[j])>0 )  
                      { 
                            strcpy(temp,arr[i]);   
                            strcpy(arr[i],arr[j]);  
                            strcpy(arr[j],temp); 
                      } 
           } 
      } 
} 

