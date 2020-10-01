#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
int peek();
void display();
typedef struct node
{
	int a;
	struct node *nxt;
}node;
node *top;
void create()
{
	top=NULL;
}  
  
int main ()  
{   int num,temp,temp2;
	int reverse=0;
	node *node;
	printf("Enter the Number\n");
	scanf("%d",&num);
	temp = num;
	create();
	while(temp){
		temp2=temp%10;
		push(temp2);
		temp/=10;
	}
	display(node);
	temp=num;
	
	while(temp)
	{
		temp2=temp%10;
		push(temp2);
		reverse=(reverse*10)+peek();
		pop();
		temp=temp/10;
		printf("\nReverse Operation :%d\n",reverse);

	}
	return 0;
 
}  
void push (int x)  
{  
	node *temp;
	temp=malloc(sizeof(node));
	temp->a=x;
	temp->nxt=top;
	top=temp;  
}  
  
void pop()  
{  
	node *temp1;
	temp1=top;
	top=top->nxt;
	free(temp1);  
} 

int isEmpty()
{
	return top==NULL;
} 

int peek(){
		if(!isEmpty())
	{
		return top->a;
	}
	else
	{
		printf("\nStack Underflow");
	}
}

void display(node *disp)
{
	int z;
	disp=top;
	printf("\nElements In stack are : ");
	while(disp!=NULL)
	{
		z=disp->a;
		printf(" %d ",z);
		disp=disp->nxt;
	}
}
