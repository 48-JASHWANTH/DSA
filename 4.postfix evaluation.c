#include<stdio.h>
#include<string.h>
#include<ctype.h>

char stack[30],postfix[30];
int top=-1;

void push(int value){
	stack[++top]=value;
}

int pop(){
	int ele;
	ele=stack[top--];
	return ele;
}

int main(){
	int i,value,op1,op2;
	printf("enter postfix expression:");
	gets(postfix);
	for(i=0;postfix[i]!='\0';i++){
		if(isalpha(postfix[i])){
			printf("enter value for %c:",postfix[i]);
			scanf("%d",&value);
			push(value);
		}else{
			op2=pop();
			op1=pop();
			switch(postfix[i]){
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;
				case '*':
					push(op1*op2);
					break;	
				case '/':
					push(op1/op2);
					break;
				case '^':
					push(op1^op2);
					break;
				default:
					printf("invalid\n");			
			}
		}
	}
	printf("ans=%d",stack[top]);
	return 0;
}
