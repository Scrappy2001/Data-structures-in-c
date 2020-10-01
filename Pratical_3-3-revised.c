#include<stdio.h>
# define N 5
int deque[N];
int f=-1;
int r=-1;
int count;

int isFull(){
	int a=0;
	if(count==N){
		a=1;
	}
	return a;
}

int isEmpty(){
	int a=0;
	if(count==0){
		a=1;
	}
	return a;
}
void enqueueFront(int x){
	if(isFull()){
		printf("the queue is full\n");
		return;
	}
	if(f==0){
		f=N-1;
	}else{
		f--;
		deque[f]=x;
		count++;
	}
}

void enqueueRear(int x){
	if(isFull()){
		printf("the queue is full\n");
		return;
	}
	r=(r+1)%N;
	deque[r]=x;
	count++;
}

void display(){
	int i=f;
	do{
		if(deque[i]!=0){
			printf("%d ",deque[i]);
		}
		i=(i+1)%N;
	}while(i!=((r+1)%N)+1);
	printf("\n");
}

int dequeueFront(){
	if(isEmpty()){
		printf("the queue is empty\n");
		return -1;
	}
	int element = deque[f];
	deque[f]=0;
	f=(f+1)%N;
	count--;
	return element;
}

int dequeueRear(){
	if(isEmpty()){
		printf("the queue is empty\n");
		return -1;
	}
	int element = deque[r];
	deque[r]=0;
	if(r==0){
		r=N-1;
	}else{
		r--;
	}
	count--;
	return element;
}

int main(){
	int choice;
	int ele;
	do{
	
		printf("Enter the choice\n");
		printf("1.EnqueueFront\n 2.EnqueueRear\n 3.DequeueFront\n 4.DequeueRear\n 5.Display\n 6.exit\n");
		scanf("%d",&choice);
			switch(choice){
			case 1: printf("Enter the element\n");
					scanf("%d",&ele);
					enqueueFront(ele);
					break;
			case 2: printf("Enter the element\n");
					scanf("%d",&ele);
					enqueueRear(ele);
					break;
			case 3: ele = dequeueFront();
					printf("The element deleted from front: %d \n",ele);
					break;
			case 4: ele = dequeueRear();
					printf("The element deleted from rear: %d \n",ele);
					break;
			case 5: printf("the elements in the queue are ");
					display();
							
			}
	}while(choice!=6);
	return 0;
}


