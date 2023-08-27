#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*top=NULL;

void push(int ele){
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = ele;
    nn->link = top;
    top = nn;
}

void display(){
    struct node *temp;
        temp = top;
        if(temp==NULL){
            printf("stack is empty\n");
        }
        else{
            while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->link;
            }
        }
}

void pop(){
    struct node *temp;
    temp = top;
    if(top==NULL){
        printf("stack is empty\n");
    }
    else{
        printf("deleted element is %d",top->data);
        top = top->link;
        free(temp);
    }
}

int main(){
    int choice,ele;
	char ch;
	do{
		printf("\n1:push 2:pop 3:display\n");
		printf("enter choice:");
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    	    printf("enter element:");
	    	    scanf("%d",&ele);
	    		push(ele);
	    		break;
	    	case 2:
				pop();
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
