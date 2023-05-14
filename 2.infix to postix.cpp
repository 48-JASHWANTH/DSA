#include<stdio.h>
#include<string.h>
#include<ctype.h>

int top=-1;
char infix[30],stack[30],postfix[30];

void push(char ch){
    stack[++top]=ch;
}

int pop(){
    char ch;
    ch=stack[top--];
    return ch;
}

int pre(char x){
    switch(x){
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
    printf("Enter infix expression:");
    gets(infix);
    push('(');
    strcat(infix,")");
    j=0;
    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='('){
            push(stack[i]);
        }
        else if(isalpha(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else{
            while(pre(stack[top])>=pre(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    postfix[j]='\0';
    printf("postfix expression is:");
    puts(postfix);
    return 0;
}

