#include<stdio.h>
#define size 3
int stack[size],top=-1;

//using it for git and git hub lol/.
void push(int ele){
	if(top==size-1){
		printf("stack is overflown\n");
	}
	else{
		stack[++top]=ele;
	}
}

void pop(void){
	int ele;
	if(top==-1){
		printf("stack is underflown\n");
	}
	else{
		ele=stack[top];
		top--;
		printf("deleted element is %d\n",ele);
	}
}

int isfull(){
	if(top==size-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void display(){
	int i;
	printf("content of stack is:\n");
	for(i=top;i>=0;i--){
		printf("%3d",stack[i]);
	}
	printf("\n");
}

int count(){
	int cnt=0,i;
	if(top==-1){
		return cnt;
	}
	else{
		for(i=top;i>=0;i--){
			cnt++;
		}
		return cnt;
	}
}

void topele(){
	if(top==-1){
		printf("there are no elements\n");	
	}
	else{
		printf("The top element is:%d\n",stack[top]);
	}
}

int main(){
	int ele,choice;
	char ch;
	do{
		printf("1:push 2:pop 3:topelement 4:isfull 5:isempty 6:display 7:count\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter element to push:");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:
			    pop();
				break;
			case 3:
				topele();
				break;
			case 4:
				if(isfull()){
					printf("stack is full\n");
				}	
				else{
					printf("stack is not full\n");
				}
				break;
			case 5:
				if(isempty()){
					printf("stack is empty\n");
				}
				else{
					printf("stack is not empty\n");
				}
				break;
			case 6:
			    display();
				break;
			case 7:
				printf("no.of elements in stack are:%d\n",count());
				break;
			default:
				printf("invalid decision\n");			
		}
		printf("do u want to continue(Y/N):");
		scanf(" %c",&ch);
		printf("\n");
	}while(ch=='y');
}
