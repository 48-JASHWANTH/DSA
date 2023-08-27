#include<stdio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;

void insert_front(int ele){
    if(front==0){
        printf("insertion from front is not possible\n");
    }
    else{
        queue[--front] = ele;
    }
}  

void insert_rear(int ele){
    if(rear==size-1){
        printf("insertion from rear is not possible\n");
    }
    else{
        queue[rear++] = ele;
    }
}  

int delete_front(){
    int ele;
    if(front == 0 && rear == -1){
        printf("deletion from front is not possible\n");
    }
    else if(front == rear){
        ele = queue[front];
        front = 0;
        rear = -1;
        return ele;
    }
    else{
        ele = queue[front];
        front++;
        return ele;
    }
} 

int delete_rear(){
    int ele;
    if(front == 0 && rear == -1){
        printf("deletion from rear is not possible\n");
    }
    else if(front == rear){
        ele = queue[rear];
        front = 0;
        rear = -1;
        return ele;
    }
    else{
        ele = queue[rear];
        rear--;
        return ele;
    }
} 

void display(){
     int i;
     if(front == -1 && rear == -1){
         printf("queue is empty\n");          
     }     
     else{
          for(i=front;i<rear;i++){
              printf("%d ",queue[i]);
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
		printf("1:insert_front 2:insert_rear 3:delete_front 4:delete_rear 5:isfull 6:isEmpty 7:display\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter element to push from front:");
				scanf("%d",&ele);
				insert_front(ele);
				break;
			case 2:
			    printf("enter element to push from rear:");
				scanf("%d",&ele);
				insert_rear(ele);
				break;
			case 3:
				ele = delete_front();
				printf("element deleted at front is %d",ele);
				break;
			case 4:
			    ele = delete_rear();
				printf("element deleted at rear is %d",ele);
				break;
			case 5:
				if(isfull()){
					printf("queue is full\n");
				}
				else{
					printf("queue is not full\n");
				}
				break;
			case 6:
			   if(isempty()){
					printf("queue is empty\n");
				}
				else{
					printf("queue is not empty\n");
				}
				break;
			case 7:
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
