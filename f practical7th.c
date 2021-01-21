
//practcal no : 7th
//application of queue

#include <stdio.h> 
#include <stdlib.h> 

struct node* createnode();
struct Queue* createQueue() ;
int enqueue(struct Queue* queue, int item, int priority); 	
int dequeue(struct Queue* queue);							  

struct node
{
		int burstt, priority ;
		struct node *ptr,*back;
};
struct Queue 
{ 
	struct node *front, *rear;
}; 

struct node* createnode()	{
	struct node *n = (struct node *)malloc( sizeof(struct node) );
	n->back=n->ptr=NULL;
	return(n);
}
struct Queue* createQueue() 	{ 
	struct Queue* queue = (struct Queue*)malloc( sizeof(struct Queue)); 
	queue->front=queue->rear=NULL;
	return queue; 
} 

struct node* min_priority(struct Queue* queue)
{
	struct node *min=queue->front,*p=queue->front;
	while(p != NULL){	
	if(p->priority < min->priority)
	min=p;
	p=p->ptr;
	}
	return (min);
}

int enqueue(struct Queue* queue, int item, int priority)  
{ 
	if(queue->front==NULL) {	
		queue->front=queue->rear=createnode();
		queue->front->burstt=item;
		queue->front->priority=priority;
		printf("%d added to queue\n", item);
	}
	else {	
		queue->rear->ptr=createnode();
		queue->rear->ptr->back=queue->rear;
		queue->rear=queue->rear->ptr;
		queue->rear->burstt=item;
		queue->rear->priority=priority;
		printf("%d added to queue\n", item); 
	}
	return 0;
} 

int dequeue(struct Queue* queue) 
{ 
	if (queue->front==NULL) 
	{	printf("queue is empty   ");	return 0; }
	struct node *pt=min_priority(queue);
	if(queue->front == queue->rear)
	{queue->front = queue->rear = NULL;
	}
	else if(pt == queue->front)
	{queue->front=queue->front->ptr;
     queue->front->back = NULL;
	}
	else if(pt == queue->rear)
	{
		queue->rear=queue->rear->back;
		queue->rear->ptr=NULL;
	}
	else
	{	pt->ptr->back = pt->back;
		pt->back->ptr = pt->ptr;
	}
	int item = pt->burstt;
	//delete(pt);
	return item; 
} 





int main() 
{ 
struct Queue* queue = createQueue(); 
int n,burst,waiting=0,turn=0,i,turnsum=0,waitsum=0,op,priority=0;
printf("\n-------------Pactical No : 7-------------\n\n");

printf("how many process you want to insert		: ");
scanf("%d",&n);

printf("\n1.without priority \n2.with priority\n");			
scanf("%d",&op)	;

switch(op)
{
	case 1:
		printf("enter process burst time		: \n");
		for(i=0;i<n;i++)
		{scanf("%d",&burst);
		enqueue(queue,burst,priority);
		}
		break;
	case 2:
		printf("enter process burst time & priority		: \n");
		for(i=0;i<n;i++)
		{scanf("%d %d",&burst,&priority);
		enqueue(queue,burst,priority);
		}
}

	printf("process  |  burst time  |  waiting time  |  turn around time  |  arrival time\n");
	burst=0;
	for(i=0;i<n;i++)
	{
		waiting=waiting+burst;
		waitsum=waitsum+waiting;
		burst=dequeue(queue);
		turn=turn+burst;
		turnsum=turnsum+turn;
		printf("  %d      |      %d      |        %d      |         %d         |        00	 \n",i+1,burst,waiting,turn);
	}	
	printf("\nAverage Waiting time =   %d",waitsum/n);
	printf("\nAverage turnaround time =   %d",turnsum/n);
	
	return 0; 
}

