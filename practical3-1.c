#include<stdio.h>
#include<stdlib.h>     
#include<ctype.h>    
#include<string.h>
#define SIZE 100 


char stack[SIZE];
int top = -1;



void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

int isDigit(char k){
	if(k >= '0' && k <= '9'){
		return 1;
	}else {
		return 0;
	}
}



void evalPostfix(char postfix[]){
	int i=0;
	float c=0;
	while(postfix[i]!='\0'){
		char ch = postfix[i];
		if(isDigit(ch-'0')){
			push(ch);
		}else if(ch == '+' || ch == '-' || ch == '*'|| ch == '/' ){
			char a = pop();
			char b = pop();
			switch(ch){
				case '+': c = a+b;
						 break;
				case '-': c = a-b;
						 break;
				case  '*': c = a*b;
						 break;
				case '/' : c = a/b;
						 break;				
			}
			
			push(c);
		
		}
		i++;
		
	}
	
	printf("the evalution of postfix expression: %d\n", pop());
}

int main()
{
	char postfix[SIZE];        
	printf("\nEnter postfix expression : ");
	gets(postfix);

	evalPostfix(postfix);                
	return 0;
}



