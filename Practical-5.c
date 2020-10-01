#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10

typedef struct node
{
    char data[max];
    struct node *next;
}node;
typedef node *list;
list head=NULL,ptr,temp;
char a[max];
void insertFromHead(){
	int ch;
	ptr = (node*)malloc(sizeof(node));
	ptr->next=NULL;
	printf("Enter Name\n");
	scanf("%s",ptr->data);
	if(head==NULL){
		head = ptr;
		return;
	}else{
		ptr->next=head;
		head= ptr;
	}
	
}


int insertInTheMiddle()
{
	int ch;
	ptr = (node*)malloc(sizeof(node));
	ptr->next=NULL;
	printf("Enter Name\n");
	scanf("%s",ptr->data);
	if(head==NULL){
		head = ptr;
		return;
	}else{
		int x,i;
		printf("Enter the position\n");
		scanf("%d",&x);
		temp=head;
		for(i=2;i<x;i++){
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next=ptr;
	}
}


void insertAtTail()
{
	int ch;
	ptr = (node*)malloc(sizeof(node));
	ptr->next=NULL;
	printf("Enter Name\n");
	scanf("%s",ptr->data);
	if(head==NULL){
		head = ptr;
		return;
	}else{
		temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next=ptr;
	}
}

void deleteNode(){
	if(head==NULL){
		printf("List is Empty\n");
	}else{
		printf("Enter the Name You want to Delete\n");
		scanf("%s",&a);
		temp= head;
		if(strcmp(a,temp->data)==0){
			head=temp->next;
		}else{
			while(strcmp(a,temp->data)!=0){
				ptr=temp;
				temp=temp->next;
				if(temp==NULL){
					printf("No such Name is Present\n");
					return;
				}
			}
			
			ptr->next=temp->next;
		}
		printf("Deleted %s\n",temp->data);
		free(temp);
	}
}

void sortNames(){
	int i,j,n=0;
	char b[max],name[max][max];
	temp=head;
	while(temp!=NULL){
		strcpy(name[n],temp->data);
		temp=temp->next;
		n++;
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(name[i],name[j])>0){
				strcpy(b,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],b);
			}
		}
	}
	n=0;
	temp=head;
	while(temp!=NULL){
		strcpy(temp->data,name[n]);
		temp=temp->next;
		n++;
	}
	
	if(head==NULL){
		printf("List is Empty\n");
	}else{
		ptr=head;
		printf("The sorted List is :\n");
		while(ptr!=NULL){
			printf("%s",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void display()
{
	if(head == NULL){
		printf("List is Empty\n");
	}else{
		ptr=head;
		while(ptr!=NULL){
			printf("%s  ",ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int main()
{	int choice;
	while(1){
		printf("Enter the choice\n");
		printf("1. Insert from the head\n");
		printf("2.Insert in the Middle\n");
		printf("3.Insert at the end \n");
		printf("4.Delete a node from the list\n");
		printf("5.Sort the names in ascending order\n");
		printf("6.Display List\n");
		printf("7.Exit\n");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: insertFromHead();
					break;
					
			case 2: insertInTheMiddle();
					break;
					
			case 3: insertAtTail();
					break;
			
			case 4: deleteNode();
					break;
			
			case 5: sortNames();
					break;
					
			case 6: display();
					break;
			case 7:exit(0);
			
			default: printf("Invalid Choice\n");
		}
	}
}

