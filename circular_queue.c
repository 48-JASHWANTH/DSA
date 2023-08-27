#include<stdio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;

void enqueue(int ele){
     if(front==-1 && rear==-1){
         front = rear = 0;
         queue[rear] = ele;
     }
     else if((rear+1)%size == front){
          printf("circular queue is full\n");
     }      
     else{
          rear = (rear+1)%size;
          queue[rear] = ele;
     }
}     

void dequeue(){
     if(front == -1 && rear==-1){
         printf("circular queue is empty\n");         
     }
     else if(front == rear){
          printf("%d is deleted",queue[front]);
          front = rear = -1;     
     }
     else{
          printf("%d is deleted",queue[front]);
          front = (front+1)%size;
     }
}     

void display(){
     int i;
     if(front == -1 && rear == -1){
         printf("queue is empty\n");          
     }     
     else{
          while(i!=rear+1){
              printf("%d ",queue[i]);
              i = (i+1)%size;
          }
          printf("\n");
     }
}

void topele(){
     printf("top element is %d",queue[front]);     
}

int isfull(){
	if(rear==size-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isempty(){
	if(front==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
    int ele,choice;
	char ch;
	do{
		printf("1:enqueue 2:dequeue 3:topelement 4:isempty 5isfull 6:display\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter element to push:");
				scanf("%d",&ele);
				enqueue(ele);
				break;
			case 2:
			    dequeue();
				break;
			case 3:
				topele();
				break;
			case 4:
				if(isfull()){
					printf("queue is full\n");
				}	
				else{
					printf("queue is not full\n");
				}
				break;
			case 5:
				if(isempty()){
					printf("queue is empty\n");
				}
				else{
					printf("queue is not empty\n");
				}
				break;
			case 6:
			    display();
				break;
			default:
				printf("invalid decision\n");			
		}
		printf("do u want to continue(Y/N):");
		scanf(" %c",&ch);
		printf("\n");
	}while(ch=='y');
	return 0;
}   
