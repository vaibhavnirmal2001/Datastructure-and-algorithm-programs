#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 10
#define EMPTY -1

struct stack {
    
    int items[SIZE];
    int top;
};

void initialize(struct stack* stackPtr);
int full(struct stack* stackPtr);
void push(struct stack* stackPtr, char value);
int empty(struct stack* stackPtr);
char pop(struct stack* stackPtr);
void removespaces(char *infix);
int Precedence(char Operator);
void InfixToPostfix(char *infix, char *postfix, struct stack *Pstack);
void remove_newline_character(char *infix);
char identifying_doubles(char *infix, char *expression);//
int finds_doubles_in_infix(int *e, char *expression);
long int Evaluate(char *postfix, int *e, struct stack *Pstack);
long int check_operator(int a, int b, char c);



int main(void) 
{
    
    char infix[100], postfix[100];
    char expression[100];
    int e[100];
    int open=0, close=0, i=0;
    long int temp; 
    struct stack Pstack;
    initialize(&Pstack);
    printf("Enter the valid Infix expression : ");
    fgets(infix, 100, stdin);
    remove_newline_character(infix);
    
    
    for(i=0; i<strlen(infix); i++)
    {
        if(infix[i]=='(')
        {
            open++; 
        }
        if(infix[i]==')')
        {
            close++; 
        }
    }
    
    if(open==close) 
    {
        removespaces(infix); 
        InfixToPostfix(infix, postfix, &Pstack);
        identifying_doubles(infix,expression);
        printf("Conversion of Postfix expression and its evaluation.\n\n");
        printf("The Postfix expression is : %s\n", postfix);
        remove_newline_character(expression);
        finds_doubles_in_infix(e,expression);
        temp=Evaluate(postfix, e, &Pstack);
        printf("The result of Postfix evaluation is : %ld\n",temp);
    }
    else
    {
        printf("The Infix Expression entered is invalid due to brackets not balanced\n");
        exit (0);
    }
    return 0;
}




void InfixToPostfix(char *infix, char *postfix, struct stack *Pstack)
{
    int i=0; 
    int x=0; 
    char temp;
    for(i=0; i<strlen(infix); i++)
    {
      
        if(infix[i]=='(')
        {
            push(Pstack,infix[i]);
        }
        
        else if(infix[i]==')')
        {
            for( ; (*Pstack).items[(*Pstack).top] !='(' ; )
            {
                postfix[x]=pop(Pstack);
                x++;
            }
            temp = pop(Pstack); 
        }
        
        
        else if(infix[i] == '0'|| infix[i] == '1'|| infix[i] == '2'|| infix[i] == '3'|| infix[i] == '4'|| infix[i] == '5'|| infix[i] == '6'|| infix[i] == '7'|| infix[i] == '8'|| infix[i] == '9')
        {
            
            postfix[x]=infix[i];
            x++;
        }
        
        
        else if(infix[i] == '^' || infix[i] == '*' || infix[i] == '%' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-')
        {
           
            for(; Precedence((*Pstack).items[(*Pstack).top]) >= Precedence(infix[i])   ;)
            {
                postfix[x]=pop(Pstack); 
                x++;
            }
            push(Pstack,infix[i]); 
        }
       
        
        else
        {
            printf("The Infix Expression entered is invalid due some foreign symbol\n");
            exit (0);
        }
    }
    
    
    for(; (*Pstack).top != -1 ;)
    {
        postfix[x]=pop(Pstack);
        x++;
    }
    postfix[x]= '\0';
}


void remove_newline_character(char *infix)
{
    int i=0;
    for(i=0; i<strlen(infix); i++)
    {
        if(infix[i]== '\n')
        {
            infix[i]= '\0';
        }
    }
}


int Precedence(char Operator) 
{
    switch(Operator)
    {
        case '^':
            return (10);
            break;
        case '/':
            return (5);
            break;
        case '%':
            return (5);
            break;
        case '*':
            return (5);
            break;
        case '+':
            return (0);
            break;
        case '-':
            return (0);
            break;
        default:
            return (-1);
    }
}

void removespaces(char *infix) 
{
    int i;
    int position = 0; 
    
    for(i = 0 ; i < strlen(infix); i++)
    {
        if(infix[i] != ' ')
        {
            infix[position] = infix[i];
            position++;
        }
    }
    infix[position]= '\0';
}

void initialize(struct stack* stackPtr) 
{
    stackPtr->top = -1;
}


void push(struct stack* stackPtr, char value) 
{
    
    if (full(stackPtr))
        return;
    
    stackPtr->items[stackPtr->top+1] = value;
    (stackPtr->top)++;
}

int full(struct stack* stackPtr) 
{
    return (stackPtr->top == SIZE - 1);
}


int empty(struct stack* stackPtr) 
{
    return (stackPtr->top == -1);
}


char pop(struct stack* stackPtr) 
{
    
    char retval;
    
    if (empty(stackPtr))
        return EMPTY;
    
    retval = stackPtr->items[stackPtr->top];
    (stackPtr->top)--;
    return retval;
}


char identifying_doubles(char *infix, char *expression)
{
    int i=0, j=0;
    for(i=0; i<strlen(infix);i++)
    {
        if(infix[i] == '0'|| infix[i] == '1'|| infix[i] == '2'|| infix[i] == '3'|| infix[i] == '4'|| infix[i] == '5'|| infix[i] == '6'|| infix[i] == '7'|| infix[i] == '8'|| infix[i] == '9')
        {
            expression[j] = infix[i];
            
            if(infix[i+1] == '0'|| infix[i+1] == '1'|| infix[i+1] == '2'|| infix[i+1] == '3'|| infix[i+1] == '4'|| infix[i+1] == '5'|| infix[i+1] == '6'|| infix[i+1] == '7'|| infix[i+1] == '8'|| infix[i+1] == '9')
            {
                expression[j+1]=infix[i+1];
                expression[j+2]=' '; 
                j++;
                j++;
                j++;
                i++;
                if(infix[i+1] == '0'|| infix[i+1] == '1'|| infix[i+1] == '2'|| infix[i+1] == '3'|| infix[i+1] == '4'|| infix[i+1] == '5'|| infix[i+1] == '6'|| infix[i+1] == '7'|| infix[i+1] == '8'|| infix[i+1] == '9')
                {
                    printf("This program doesn't support evaluation of numbers with three digits or more. Please enter a valid one ot two digit numbers\n");
                    exit (0);
                }
            }
            
            
            else if(infix[i+1] != '0'|| infix[i+1] != '1'|| infix[i+1] != '2'|| infix[i+1] != '3'|| infix[i+1] != '4'|| infix[i+1] != '5'|| infix[i+1] != '6'|| infix[i+1] != '7'|| infix[i+1] != '8'|| infix[i+1] != '9')
            {
                infix[i+1]=' ';
                expression[j+1]=infix[i+1];
                j++;
            }
        }
        
       
        else if(infix[i] != '0'|| infix[i] != '1'|| infix[i] != '2'|| infix[i] != '3'|| infix[i] != '4'|| infix[i] != '5'|| infix[i] != '6'|| infix[i] != '7'|| infix[i] != '8'|| infix[i] != '9')
        {
            infix[i]=' ';
            expression[j]=infix[i];
            j++;
        }
    }
    return 0;
}

int finds_doubles_in_infix(int *e, char *expression)
{
    int k=0;
    int i;
    
	for( i=0; i<strlen(expression);i++)
    {
        if(expression[i] == '0'|| expression[i] == '1'|| expression[i] == '2'|| expression[i] == '3'|| expression[i] == '4'|| expression[i] == '5'|| expression[i] == '6'|| expression[i] == '7'|| expression[i] == '8'|| expression[i] == '9')
        {
            if(expression[i+1] == '0'|| expression[i+1] == '1'|| expression[i+1] == '2'|| expression[i+1] == '3'|| expression[i+1] == '4'|| expression[i+1] == '5'|| expression[i+1] == '6'|| expression[i+1] == '7'|| expression[i+1] == '8'|| expression[i+1] == '9')
            {
                e[k]=((expression[i]-'0')*10)+(expression[i+1]-'0');
                k++;
                i++;
            }
            else
            {
                e[k]=(expression[i]-'0');
                k++;
            }
        }
        else if (expression[i]==' ')
        {
            continue;
        }
    }
    return 0;
}

long int Evaluate(char *postfix, int *e, struct stack *Pstack)
{
    int i=0, a=0, b=0, j=0;
    
    for(i=0; i<strlen(postfix); i++)
    {
    
        if(postfix[i] == '^' || postfix[i] == '*' || postfix[i] == '%' || postfix[i] == '/' || postfix[i] == '+' || postfix[i] == '-')
       {
           a=pop(Pstack);
           b=pop(Pstack);
           push(Pstack,check_operator(a, b, postfix[i]));
       }
      
        
        if(postfix[i] == '0'|| postfix[i] == '1'|| postfix[i] == '2'|| postfix[i] == '3'|| postfix[i] == '4'|| postfix[i] == '5'|| postfix[i] == '6'|| postfix[i] == '7'|| postfix[i] == '8'|| postfix[i] == '9')
        {
            push(Pstack, e[j]); 
            if(e[j]>=10)
            {
                i++;
            }
            j++;
        }
        if(strlen(postfix)==1) 
        {
            printf("Evaluation will not be possible as there was an invalid infix expression entered\n");
            exit (0);
        }
    }
    return pop(Pstack);
}


long int check_operator(int a, int b, char c)
{
    switch(c)
    {
        case '^':
            return pow(b,a);
            break;
        case '/':
            return b/a;
            break;
        case '%':
            return b%a;
            break;
        case '*':
            return a*b;
            break;
        case '+':
            return a+b;
            break;
        case '-':
            return b-a;
            break;
        default:
            return (0);
    }
}

