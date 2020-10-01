// Name- Karan Parmar Roll No- B_306
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct Stack{
	int top;
	char a[SIZE];
}Stack;
Stack s;
int isEmpty(){
	return s.top == -1;
}

int isFull(){
	return s.top== SIZE-1;
}

void push(char x){
	if(isFull()){
		return;
	}
	s.top++;
	s.a[s.top] = x;
}

char StackTop(){
	if(isEmpty()){
		return 0;
	}
	return s.a[s.top];
}

char pop(){
	if(isEmpty()){
		return 0;
	}
	char x ;
	x = s.a[s.top];
	return x;
}

int isOperator(char x){
	if(x == '+' || x == '+' || x == '-' || x == '*' || x == '/' ||x == '$' || x == '(' || x == ')')
		return 1;
	return 0;
}

char * prefix_infix(char *str){
	int n,i,j=0;
	char a,b,op;
	char *infix= (char*)malloc(strlen(str)*sizeof(char));
	for(i=0;i<strlen(str);i++){
		if(isOperator(str[i]))
			push(str[i]);
		else{
			op = pop();
			a = str[i];
			infix[j++] = a;
			infix[j++] = op;
		}
	}
	return infix;
}

int main()
{
	char *infix = malloc(sizeof(char) * 25);
	printf("Enter the expression");
	gets(infix);
	push(' ');
	char * str = prefix_infix(infix);
	printf("Infix Expression");
	puts(str);
	return 0;	
}

