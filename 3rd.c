#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BLANK ' '
#define TAB '\t'
#define MAX 50
void push( int x);
int pop();
void infix_to_postfix();
 int eval_post();
int priority(char x);
int isEmpty();
int white_space(char );
char infix[MAX], postfix[MAX];
int stack[MAX];
int top;
int main()
{
 int value;
 top=-1;
 printf("Enter infix : ");
 gets(infix);
 infix_to_postfix();
 printf("Postfix : %s\n",postfix);
 value=eval_post();
 
 printf("Value of expression : %ld\n",value);
 return 0;
}
void infix_to_postfix()
{
 int i,p=0;
 char next;
 char x;
 for(i=0;i<strlen(infix);i++)
 {
 x=infix[i];
 if(!white_space(x))
 {
 switch(x)
 {
 case '(':
 push(x);
 break;
 case ')':
 while((next=pop())!='(')
 postfix[p++] = next;
 break;
 case '+':
 case '-':
 case '*':
 case '/':
 case '%':
 case '^':
 
 while( !isEmpty( ) && priority(stack[top])>= priority(x) )
 postfix[p++]=pop();
 push(x);
 break;
 default:
 postfix[p++]=x;
 }
 }
 }
 while(!isEmpty( ))
 postfix[p++]=pop();
 postfix[p]='\0';
}
int priority(char x)
{
 switch(x)
 {
 case '(':
 return 0;
 case '+':
 case '-':
 return 1;
 case '*':
 case '/':
 case '%':
 return 2;
 case '^':
 return 3;
 default :
 return 0;
 }
 
}
void push(int x)
{
 if(top>MAX)
 {
 printf("Stack overflow\n");
 exit(1);
 }
 if (! isEmpty() && stack[top] >= 0 && stack[top] <= 10)
 {
 stack[top] *= 10;
 stack[top] += x;
 }
 else
 {
 stack[++top]=x;
 }
}
 int pop()
{
 if( isEmpty() )
 {
 printf("Stack underflow\n");
 exit(1);
 }
 return (stack[top--]);
}
int isEmpty()
{
 if(top==-1)
 
 return 1;
 else
 return 0;
}
int white_space(char x)
{
 if( x == BLANK || x == TAB )
 return 1;
 else
 return 0;
}
int eval_post()
{

 int a,b,temp,result;
 int i;
 for(i=0;i<strlen(postfix);i++)
 {
 if(postfix[i]<='9' && postfix[i]>='0')
 push(postfix[i]-'0');
 else
 {
 a=pop();
 b=pop();
 switch(postfix[i])
 {
 case '+':
 temp=b+a; break;

 case '-':
 temp=b-a;break;
 case '*':
 temp=b*a;break;
 case '/':
 temp=b/a;break;
 case '%':
 temp=b%a;break;
 case '^':
 temp=pow(b,a);
 }
 push(temp);
 }
 }
 result=pop();
 return result;
}
