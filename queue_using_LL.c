#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*front = NULL,*rear = NULL;

void enqueue(int ele){
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = ele;
    nn->link = NULL;
    if(front == NULL && rear == NULL){
        front = rear = nn;
    }
    else{
        rear->link = nn;
        rear = nn;
    }
}

void display(){
    struct node *temp;
    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else{
        temp = front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
}

void dequeue(){
    struct node *temp;
    temp = front;
    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else{
        printf("deleted element is %d",front->data);
        front = front->link;
        free(temp);
    }
}

int main(){
    int choice,ele;
	char ch;
	do{
		printf("\n1:enqueue 2:dequeue 3:display\n");
		printf("enter choice:");
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    	    printf("enter element:");
	    	    scanf("%d",&ele);
	    		enqueue(ele);
	    		break;
	    	case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("Invalid choice\n");						
		}
		printf("Do u want to continue on main(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
	return 0;
}    
