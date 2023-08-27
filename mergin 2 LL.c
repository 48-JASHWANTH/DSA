#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*first=NULL,*second=NULL,*temp,*nn;

struct node *create(struct node *f){
	char ch;
	do{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d", &nn->data);
		if(f==NULL){
			temp=nn;
			f=nn;
		}
		else{
			temp->link=nn;
			temp=nn;
		}
		printf("continue(y/n):");
		scanf(" %c",&ch);
	}while(ch=='y');
	nn->link=NULL;
	return f;
}

void display(struct node *t){
	if(t==NULL){
		printf("empty list\n");
	}
	else{
		temp=t;
		while(temp!=NULL){
			printf("%3d",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

struct node *merge(struct node *t1,struct node *t2){
	struct node *f1=t1, *f2=t2, *f3=NULL;
	struct node *prev=NULL, *cur=NULL;
	while(f1!=NULL && f2!=NULL){
		if(f1->data <= f2->data){
			if(f3==NULL){
				f3=f1;
				cur=f3;
			}
			else{
				cur->link=f1;
				cur=cur->link;
			}
			f1=f1->link;
		}
		else{
			if(f3==NULL){
				f3=f2;
				cur=f3;
			}
			else{
				cur->link=f2;
				cur=cur->link;
			}
			f2=f2->link;
		}
	}
	if(f1!=NULL){
		cur->link=f1;
	}
	else{
		cur->link=f2;
	}
	return f3;
}

int main(){
	printf("Enter first list:\n");
	first=create(first);
	printf("Content of first list is:\n");
	display(first);
	printf("Enter second list:\n");
	second=create(second);
	printf("Content of second list is:\n");
	display(second);
	first=merge(first,second);
	printf("Merged list is:\n");
	display(first);
	return 0;
}

