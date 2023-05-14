#include<stdio.h>
#include<string.h>
#include<ctype.h>

char prefix[100],stack[100];
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
	printf("enter expression:");
	gets(prefix);
	strrev(prefix);
	for(i=0;prefix[i]!='\0';i++){
		if(isalpha(prefix[i])){
			printf("enter value for %c:",prefix[i]);
			scanf("%d",&value);
			push(value);
		}
		else{
			op1=pop();
			op2=pop();
			switch(prefix[i]){
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
}
