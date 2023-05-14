#include<stdio.h>
#include<string.h>
#include<ctype.h>

char infix[30],stack[30],prefix[30];
int top=-1;

void push(int ele){
	stack[++top]=ele;
}

int pop(){
	char ch;
	ch=stack[top--];
	return ch;
}

int prec(char ch){
	switch(ch){
		case '/':
		case '*':
		case '%':
			return 7;
		case '+':
		case '-':
			return 5;
		default:
			return 0;		
	}
}

int main(){
	int i,j;
	printf("enter infix expression:");
	gets(infix);
	strrev(infix);
	push(')');
	strcat(infix,"(");
	j=0;
	for(i=0;infix[i]!='\0';i++){
		if(infix[i]==')'){
			push(infix[i]);
		}
		else if(isalpha(infix[i])){
			prefix[j++]=infix[i];
		}
		else if(infix[i]=='('){
			while(stack[top]!=')'){
				prefix[j++]=pop();
			}
			pop();
		}
		else{
			while(prec(stack[top])>prec(infix[i])){
				prefix[j++]=pop();
			}
			push(infix[i]);
		}
		prefix[j]='\0';
	}
	strrev(prefix);
	printf("prefix expression is:");
	puts(prefix);
	return 0;
}
