#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void accept_data(int);
void display_data();
struct store
{
 char name[20];
 int quantity;
 struct store *ptr;
};
struct store *headveg=NULL;
struct store *headfruit=NULL;
struct store* createNode()
{
 struct store *n;
 n=(struct store *)malloc( sizeof(struct store) );
 return(n);
}
void insertNodeveg()
{
 struct store *temp,*t;
 temp=createNode();
 printf("enter vegetable name : ");
 scanf("%s",&temp->name);
 printf("enter quantity of %s : ",temp->name);
 scanf("%d",&temp->quantity);
 temp->ptr=NULL;

 if(headveg==NULL)
 headveg=temp;
 else
 {
 t=headveg;
 while(t->ptr!=NULL)
 t=t->ptr;
 t->ptr=temp;
 }
}
void insertNodefruit()
{
 struct store *temp,*t;
 temp=createNode();
 printf("enter fruit name : ");
 scanf("%s",&temp->name);
 printf("enter quantity of %s : ",temp->name);
 scanf("%d",&temp->quantity);
 temp->ptr=NULL;

 if(headfruit==NULL)
 headfruit=temp;
 else
 {
 t=headfruit;
 while(t->ptr!=NULL)
 t=t->ptr;
 t->ptr=temp;
 }
}
void sort(struct store *head)
{
 struct store *i,*j;
 int temp;
 char tep[10];
 for(i=head;i!=NULL;i=i->ptr)
 {
 for(j=i->ptr;j!=NULL;j=j->ptr)
 {
 if(i->quantity < j->quantity)
 {
 temp =i->quantity;
 i->quantity=j->quantity;
 j->quantity=temp;
 strcpy(tep ,i->name);
 strcpy(i->name,j->name);
 strcpy(j->name,tep);
 }
 }
 }
}
int main()
{
 int i,j,option=0;

 while(option !=4)
 {
 printf("\n-----------------------%%%%%%%%----------------------WELCOME TO FRUITS AND VEGTABLE MALL-----------------%%%%%%%%%%----------------------------\n");
 printf("!!!!!!!! Enter your choice !!!!!!!!!\n");
 printf("1 -> For Accept Vegetable data \n");
 printf("2 -> For Accept Fruits data \n");
 printf("3 -> For Display Sorted data\n");
 printf("4 -> For exit\n");
 printf("\nenter your choice : ");
 scanf("%d",&option);
 switch(option)
 {
 case 1:
 accept_data(1);
 break;
 case 2:
 accept_data(2);
 break;
 case 3:
 display_data();
 break;
 }
}
}
void accept_data(int option)
{
 int a,i;
 printf("enter no.of product do you want to add : ");
 scanf("%d",&a);
 for(i=0;i<a;i++)
 {
 if(option==1)
 insertNodeveg();
 else
 insertNodefruit();
 }
 }
void display_data()
{
 sort(headveg);
 sort(headfruit);
 struct store *i;
 printf("\n");
 printf("VEGETABLE NAME QUANTITY \n");
 for(i=headveg;i!=NULL;i=i->ptr)
 printf("%s %d \n",i->name,i->quantity);
 printf("\n");
 printf("FRUIT NAME QUANTITY \n");
 for(i=headfruit;i!=NULL;i=i->ptr)
 printf("%s %d \n",i->name,i->quantity);
}
