#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*first=NULL,*temp,*nn;

struct node *create_SLL(struct node *first){
	char ch;
	do{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&nn->data);
		if(first==NULL){
			first=nn;
			temp=nn;
		}
		else{
			temp->link=nn;
			temp=nn;
		}
		printf("Continue on create(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
	temp->link=NULL;
	return first;
}

void display(){
	if(first==NULL){
		printf("SLL is empty\n");
	}
	else{
		printf("Content of SLL is:");
		temp=first;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int count(){
	int cnt=0;
	if(first==NULL){
		return cnt;
	}
	else{
		temp=first;
		while(temp!=NULL){
			cnt++;
			temp=temp->link;
		}
		return cnt;
	}
}

void insert_beg(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	if(first==NULL){
		first=nn;
		nn->link=NULL;
	}
	else{
		nn->link=first;
		first=nn;
	}
}

void insert_end(){
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&nn->data);
	if(first==NULL){
		first=nn;
		nn->link=NULL;
	}
	else{
		temp=first;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		temp->link=nn;
		nn->link=NULL;
	}
}

void insert_pos(){
	int pos;
	int cnt=count();
	printf("enter pos:");
	scanf("%d",&pos);
	if(pos==1){
		insert_beg();
	}
	else if(pos==cnt){
		insert_end();
	}
	else if(pos>cnt+1){
		printf("Invalid position\n");
	}
	else{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter data:");
		scanf("%d",&nn->data);
		int i=1;
		temp=first;
		while(i<pos-1){
			temp=temp->link;
			i++;
		}
		nn->link=temp->link;
		temp->link=nn;
	}
}

void insert(){
	int choice;
	char ch;
	do{
		printf("1:insertBeg 2:insertEnd 3:insertPos\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert_beg();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_pos();
				break;
			default:
				printf("Invalid choice\n");		
		}
		printf("Do u want to continue insertion(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
}


void delete_beg(){
	if(first==NULL){
		printf("SLL is empty\n");
	}
	else{
		temp=first;
		first=first->link;
		free(temp);
		printf("Deletion at beginning is done\n");
	}
}

void delete_end(){
	if(first==NULL){
		printf("SLL is empty\n");
	}
	else{
		struct node *prev_node;
		temp=first;
		while(temp->link!=NULL){
			prev_node=temp;
			temp=temp->link;
		}
		prev_node->link=NULL;
		free(temp);
	}
}

void delete_pos(){
	int pos;
	int cnt=count();
	printf("enter position:");
	scanf("%d",&pos);
	if(pos==1){
		delete_beg();
	}
	else if(pos==cnt){
		delete_end();
	}
	else if(pos>cnt){
		printf("Deletion not possible\n");
	}
	else{
		struct node *prev_node;
		int i=1;
		temp=first;
		while(i<pos){
			prev_node=temp;
			temp=temp->link;
			i++;
		}
		prev_node->link=temp->link;
		free(temp);
		printf("Deletion is done at the position\n");
	}
}

void Delete(){
	int choice;
	char ch;
	do{
		printf("1:deleteBeg 2:deleteEnd 3:deletePos\n");
		printf("enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				delete_beg();
				break;
			case 2:
				delete_end();
				break;
			case 3:
				delete_pos();
				break;
			default:
				printf("Invalid choice\n");		
		}
		printf("Do u want to continue deletion(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
}

void search(){
	int ele,flag=0;
	printf("Enter element to search:");
	scanf("%d",&ele);
	temp=first;
	while(temp!=NULL){
		if(temp->data==ele){
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(flag==1)
		printf("element is found\n");
	else
		printf("element is not found\n");
}

int main(){
	int choice;
	char ch;
	do{
		printf("\n1:create 2:insert 3:delete 4:display 5:count 6:search\n");
		printf("enter choice:");
	    scanf("%d",&choice);
	    switch(choice){
	    	case 1:
	    		first=create_SLL(first);
	    		break;
	    	case 2:
				insert();
				break;
			case 3:
				Delete();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("no of elements:%d\n",count());
				break;
			case 6:
				search();
				break;
			default:
				printf("Invalid choice\n");						
		}
		printf("Do u want to continue on main(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
	return 0;
}
