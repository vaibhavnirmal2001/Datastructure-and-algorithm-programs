#include <iostream>
using namespace std;
void creatheap(int arr[],int end)
{   int i,k,m;
    for(i=1;i<=end;i++)
    {   k=i;
        while(k>0)
        {   m= k%2==0 ? (k/2)-1 : k/2 ;
            if(arr[k]>arr[m])
            {   swap(arr[k],arr[m]);
                k=m;
            }
            else
            break;
        }
    } 
}

void heapsort(int arr[], int size)
{   int i,end=size-1;
    for(i=0;i<size;i++)
    {   creatheap(arr,end);
        swap(arr[0],arr[end]);
        end--;
    }
}

int main()
{
  int size,i,j;  
  cout<<"enter number of elements to sort   : ";
  cin>>size;
  int arr[size];
  cout<<"enter elements in array    : ";
  for(i=0;i<size;i++)
        cin>>arr[i];
heapsort(arr,size);
   cout<<"after sorting array is    : \n" ;
   for(i=0;i<size;i++)
        cout<<arr[i] <<" ";
}


