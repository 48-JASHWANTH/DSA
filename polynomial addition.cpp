#include<stdio.h>
#include<stdlib.h>

struct node{
	int coeff;
	int pow;
	struct node *link;
}*f1=NULL,*f2=NULL,*f3=NULL,*nn,*temp;

struct node *createPoly(struct node *first){
	char ch;
	do{
		nn=(struct node*)malloc(sizeof(struct node));
		printf("enter coeff & pow : ");
		scanf("%d%d",&nn->coeff,&nn->pow);
		if(first==NULL){
			first=nn;
			temp=nn;
		}
		else{
			temp->link=nn;
			temp=temp->link;
		}
		printf("continue on creation:");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	nn->link=NULL;
	return first;
}

void display(struct node *t){
	if(t==NULL){
		printf("There is no polynomial\n");
	}
	else{
		temp=t;
		while(temp->link != NULL){
			printf("%dx^%d+",temp->coeff,temp->pow);
			temp=temp->link;
		}
		printf("%dx^%d",temp->coeff,temp->pow);
		printf("\n");
	}
}

struct node *addPoly(struct node *p1, struct node *p2, struct node *p3){
	int x, y;
	while(p1!=NULL && p2!=NULL){
		if(p1->pow > p2->pow){
			x = p1->pow;
			y = p1->coeff;
			p1 = p1->link;
		}
		else if(p2->pow > p1->pow){
			x = p2->pow;
			y = p2->coeff;
			p2 = p2->link;
		}
		else{
			x = p1->pow;
			y = p1->coeff + p2->coeff;
			p1 = p1->link;
			p2 = p2->link;
		}
		nn = (struct node*)malloc(sizeof(struct node));
		nn->pow = x;
		nn->coeff = y;
		nn->link = NULL;
		if(p3 == NULL){
			p3 = nn;
			temp = nn;
		}
		else{
			temp->link = nn;
			temp = nn;
		}
	}
	while(p1 != NULL){
		nn = (struct node*)malloc(sizeof(struct node));
		nn->pow = p1->pow;
		nn->coeff = p1->coeff;
		nn->link = NULL;
		temp->link = nn;
		temp = nn;
		p1 = p1->link;
	}

	while(p2 != NULL){
		nn = (struct node*)malloc(sizeof(struct node));
		nn->pow = p2->pow;
		nn->coeff = p2->coeff;
		nn->link = NULL;
		temp->link = nn;
		temp = nn;
		p2 = p2->link;
	}

	return p3;
}

int main(){
	printf("Enter first polynomial:\n");
	f1=createPoly(f1);
	display(f1);
	printf("Enter second polynomial:\n");
	f2=createPoly(f2);
	display(f2);
	printf("Polynomial after addition is:\n");
	f3=addPoly(f1,f2,f3);
	display(f3);

	return 0;
}

