
//practcal no : 9th
//heap sort algorithm


#include<stdio.h>
void main()
{
  int n,i,heap[50],temp;
  printf("\n-------------------Practical 9th-----------------------\n");

  printf("\nEnter the size of heap : ");
  scanf("%d",&n);
  printf("\nEnter the Elements  : ");
  for(i=0;i<n;i++)
  {
      scanf("%d",&heap[i]);
  }
  printf("The tree formed during process are : \n");
  heapsort(heap,n);
  printf("\nThe tree is : %d \n",heap[0]);
  printf("\nThe sorted array is : ");
  for(i = 0;i<n; i++)
  {
      printf("%d ",heap[i]);
  }

}

 void maxheap(int heap[] ,int n,int i)
 {
     int largest = i;
     int l = (i*2)+1;																	
     int r =(i*2)+2;
     int temp,k;
     if ( l < n && heap[l] > heap[largest])
     {
         largest = l;
     }
     if( r < n && heap[r] > heap[largest])
     {
         largest = r;
     }
     if (largest != i)
     {
         temp = heap[largest];
         heap[largest] = heap[i];
         heap[i] = temp;
         maxheap(heap,n,largest);

     }
 }
 void heapsort(int heap[],int n)
 {
     int temp,i,k;
     for ( i = (n/2)-1; i >=0; i--)
     {
        maxheap(heap,n,i);
     }
     for ( i = n-1; i >0; i--)
     {
         printf("\nThe tree is : ");
         for ( k = 0; k < i+1; k++)
         {
             printf("%d ",heap[k]);
         }
         printf("\n");
         temp = heap[0];
         heap[0]= heap[i];
         heap[i] = temp;
         maxheap(heap,i,0);
     }
 }

