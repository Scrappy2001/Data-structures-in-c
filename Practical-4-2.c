#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    char name[20];
    struct Node *next;
}*head = NULL;

void LinkedListCreate(int n){
	int i;
	struct Node *last_node,*t;
	head = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter name of 1:");
	scanf("%s",&head->name);
	printf("\nEnter key of 1:");
	scanf("%d",&(head->key));
	head->next = head;
	last_node = head;
	for(i=2;i<=n;i++){
		t = (struct Node *)malloc(sizeof(struct Node));
		printf("\nEnter name of %d:",i);
		scanf("%s",&t->name);
		printf("\nEnter key of %d:",i);
		scanf("%d",&(t->key)); 
		t->next = last_node->next;
		last_node->next = t;
		last_node = t;
	}
}

void delete(int pos){
    struct Node *p = head;
	struct Node *q;
    int i;
    if(pos == 1){
        while(p->next != head)
            p = p->next;
        if(head == p){
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else{
        for(i=0;i<pos-2;i++)
            p=p->next;
        q = p->next;
        p->next = q->next;
        free(q);
    }
}

void display(struct Node *h){
    printf("\n");
    do{
        printf("%d ",h->key);
        h = h->next;
    }while(h!=head);
    printf("\n");
}

int logic(int m,int n){
	int z=n;
	while(n!=1){
		delete(m);
		display(head);
		m = (m+1)%z;
		n--;
	}
	printf("\nThe winner is:\n");
	printf("%d\n",head->key);
	printf("%s\n",head->name);
}

int main(){
    int n,m;
	printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter m:");
    scanf("%d",&m);
    LinkedListCreate(n);
    logic(m,n);
}
