#include<stdio.h>

void postfix();
char stack[50];
int s[50];
char post[50];
int p = -1;
int top = -1;
int rtop = -1;
int xtop=-1;      
 
xpush(int elem)
{     
 s[++xtop]=elem;                
}

int xpop()
{                      
 return(s[xtop--]);
}

void push(char x)
{
 stack[++top] = x;
}
 
char pop()
{
    if(top == -1)
        return -1;
    else
     return stack[top--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

main()
{
 int choice;
 do
 {
 	printf("=============================================================================================\n");
  printf("---------------------------------------MENU--------------------------------------------------------\n");

  	printf("=============================================================================================\n");
  printf("\n Choose any one\n");
    printf("1.INFIX to POSTFIX conversion:");
    printf("\n 2.EXIT\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1 : postfix();break;
   case 2 : printf("\t YOU EXIT FROM THE PROGRAM \N");break;
   default: printf("PLEASE ENTER VALID INPUT\n");
  }
 }while(choice!=2);
}

void postfix()
{
 p=-1;
    char exp[20];
    char *e, x;
    printf("Enter infix expression = ");
    scanf("%s",exp);
    printf("\nPostfix expression = ");
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
   printf("%c",*e);
            post[++p]=*e;
        }
        else if(*e == '(')
      push(*e);
      
  else if(*e == ')')
        {
            while((x = pop()) != '(')
         {
    printf("%c", x);
          post[++p]=x;
         }
        }
     else
     {
         while(priority(stack[top]) >= priority(*e))
         {
          char a;
          a= pop();
       printf("%c",a);
             post[++p]=a;
         }
         push(*e);
     }
        e++;
    }
 while(top != -1)
 {
  char b;
  b=pop();
     printf("%c",b);
     post[++p]=b;
 }
    
// EVALUATION PART OF PROGRAM
 int i=0,op1,op2;
 char ch;
 while(i != (p+1))
 {
  ch=post[i];
  i++;
  if(isdigit(ch))
   xpush(ch-'0'); 
  else
  {        
   op2=xpop();
   op1=xpop();
   switch(ch)
   {
   case '+':xpush(op1+op2);break;
   case '-':xpush(op1-op2);break;
   case '*':xpush(op1*op2);break;
   case '/':xpush(op1/op2);break;
   }
  } 
 }
   printf("\n\n RESULT OF EVALUATION IS : %d\n",s[xtop]);
}

