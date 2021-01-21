
#include<stdio.h>
#include<stdlib.h>

void accept_data(int);
void sort_data(int);
void display_data();

struct store
{
	char name[20];
	int amount;
	struct store *ptr;
}veg,fruit;

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
	printf("enter name of vegetable \t: ");
	scanf("%s",&temp->name);
	printf("enter amount of %s \t:",temp->name);
	scanf("%d",&temp->amount);
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
	printf("enter fruit name 	: ");
	scanf("%s",&temp->name);
	printf("enter amount of %s	   :	",temp->name);
	scanf("%d",&temp->amount);
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
	
	for(i=head;i!=NULL;i=i->ptr)
	{
		for(j=i->ptr;j!=NULL;j=j->ptr)
		{
			if(i->amount > j->amount)
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
		printf("_______________________________________________________________________________________________________________");
	printf("\n \t \t \t[ %d ] ## WELCOME TO THE MALL OF FRUITS AND VEGTABLES ##\t \t \t\n",option+1);
		printf("_______________________________________________________________________________________________________________");
	
	printf("\n choose");
	printf("\t 1 ) For Accept Vegetable data \n");
	printf("\t 2 ) For Accept Fruits data \n");
	printf("\t 3 ) For Display Sorted data\n");
	printf("\t 4 ) For exit\n");
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


option++;
}

void accept_data(int option)
{ 
	int a,i;
	printf("enter number of products:");
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
	printf("\n the list in sorted manner is:\n");

	printf("VEGETABLE NAME\t\t	QUANTITY	\n");
	for(i=headveg;i!=NULL;i=i->ptr)
		printf("%s	\t\t\	%d	\n",i->name,i->amount);
	printf("\n");
	printf("FRUIT NAME\t\t	QUANTITY	\n");	
	for(i=headfruit;i!=NULL;i=i->ptr)
		printf("%s	\t\t	%d	\n",i->name,i->amount);
	
	
}

