#include<stdio.h>
#include<stdlib.h>
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
void push(int x)
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
int peek()
{
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
void main()
{
	int num,rev=0,tmp,tmp2;
	node *disp;
	printf("\nEnter a Number : ");
	scanf("%d",&num);
	tmp=num;
	create();
	while(tmp)
	{
		tmp2=tmp%10;
		push(tmp2);
		tmp=tmp/10;
	}
	display(disp);
	tmp=num;
	while(tmp)
	{	
		tmp2=tmp%10;
		push(tmp2);
		rev=(rev*10)+peek();
		pop();
		tmp=tmp/10;
		printf("\nReverse Operation :%d\n",rev);
	}
	printf("\nReverse Of %d is :  %d",num,rev);
}
