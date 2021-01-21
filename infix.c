#include<cstring>
#include <sstream>
#include<stdlib.h>
#include<iostream>
using namespace std;

int sizee;

struct arraystack* createstack(int cap);
void push(struct arraystack *ptr,int element);
int pop(struct arraystack *ptr);
int isempty(struct arraystack *ptr);
int isfull(struct arraystack *ptr);
int is_operator(int item);
int precedence(int item);
int Evaluation(string ans,struct arraystack *ptr);

struct arraystack
{
    int top;
    int capacity;
    int *arrey;
};
struct arraystack* createstack(int cap)
{
    struct arraystack *ptr;
    ptr=(struct arraystack*)malloc(sizeof(struct arraystack));
    ptr->top=-1;
    ptr->capacity=cap;
    ptr->arrey=(int*)malloc(sizeof(char)*cap);
    return(ptr);
}
int is_operator(int item)
{
	if(item=='^' ||  item=='/' ||  item=='*' ||  item=='+' ||  item=='-')
	return(1);
	else
	return(0);
}
int precedence(int item)
{
	if(item=='^')
	return(3);
	else if(item=='/' || item=='*')
	return(2);
	else if(item=='+' || item=='-')
	return(1);
	else
	return(0);
}
int isfull(struct arraystack *ptr)
{
    if(ptr->top == (ptr->capacity-1))  
        {        return(1);}
    else
    return(0);
}
int isempty(struct arraystack *ptr)
{
    if(ptr->top == -1)  
        {		return(1);}
    else
    return(0); 
}
void push(struct arraystack *ptr,int element)
{
    if(isfull(ptr)==0 )
    {
        ++ptr->top;
        ptr->arrey[ptr->top]=element;
    }
    else
    cout<<"nannot push STACK IS FULL\n";
	
}
int pop(struct arraystack *ptr)
{
	int item=0;
    if(isempty(ptr)==0)
    {
        item=ptr->arrey[ptr->top];
        ptr->top=((ptr->top)-1);
        return(item);
    }
    else
    printf("cannot pop STACK IS EMPTY \n"); 
	return(item);
}
int main()
{
	int size,i,j=0;
	struct arraystack *ptr;
	char Q[20];
    cout<<"Enter the expression	: ";
    cin>>Q;
	size=strlen(Q);
	Q[size]=')';
	ptr=createstack(size);

	push(ptr,'(');
	
	stringstream ss,ans;
	ss<<Q;
	int p;
	char ch;
	
	while(ss>>p)
	{
			ans<<p;
			ans<<" ";
			
		ss>>ch;
		
		if(ch=='(') 
		push(ptr,'(');
		else if( is_operator(ch)==1 )
		{
			char temp=pop(ptr);
			while(is_operator(temp)==1 && precedence(temp)>=precedence(ch))
			{
				ans<<temp;
				ans<<" ";
				temp=pop(ptr);
			}
			push(ptr,temp);
			push(ptr,ch);
		}
		else if( ch==')' )
		{
			while(ptr->arrey[ptr->top]!='(')
			{
				char temp=pop(ptr);
				ans<<temp;
				ans<<" ";
			}
			pop(ptr);
		}
		else
		cout<<"WRONG EXPRESSION	";
	}
	cout<<"The postfix expression is	:	"<<ans.str()<<endl;
	sizee=ans.str().length();
	string st;
	st=ans.str();
	cout<<"\nThe result of Postfix evaluation is   :	"<<Evaluation(st,ptr);
    return 0;
}
int Evaluation(string ans,struct arraystack *ptr)
{
	while(ptr->top!=-1)
	{	pop(ptr);		}
	int a,op1,op2,op3,i;
	char ch;
	
for(i=0;i<=sizee;i++)
{
	if(isdigit(ans[i]))
	{
		int num=0;
		while(isdigit(ans[i]))  
            {  
            num = num * 10 + (int)(ans[i] - '0');  
                i++;
            } 
        i--;
		push(ptr,num);		
	}	
	else if(ans[i]=='+' || ans[i]=='-' || ans[i]=='*' || ans[i]=='/' )
	{
		ch=ans[i];
		op2=pop(ptr);
		op1=pop(ptr);
		switch(ch)
		{case '+':	op3=op1+op2;	break;	
		 case '-':	op3=op1-op2;	break;
		 case '*':	op3=op1*op2;	break;
		 case '/':	op3=op1/op2;	break;
		}
		push(ptr,op3);
	}	
}
return pop(ptr);
}



