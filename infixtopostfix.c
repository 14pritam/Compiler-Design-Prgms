
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>


void push(char ch);
void pop();
void inftopost(char exp[20]);
int precedence(char k);
//int isoperator(char j);

char stack[20];
int top=-1;


void pop() {
if(top!=-1)
top--;
else
printf("\nError\n");
}

void push(char ch) {
if(top<20)
stack[++top]=ch;
else
printf("\nOverflow Error.\n");
}

/*int isoperator{char j) {
  if(j=='^' || j=='+' || j=='-' || j=='/' || j=='*' )
    return 1;
  else
    return 0;
}*/

int precedence(char k) {
if(k=='^')
    return 3;
else if(k=='*' || k=='/')
    return 2;
else if(k=='+' || k=='-')
    return 1;
else
    return 0;
}


void inftopost(char exp[20]) {
int i=0;
while(exp[i]!=';') {
        if(isalpha(exp[i]) || isdigit(exp[i]))
                   printf("%c",exp[i]);
        else if(exp[i]=='(')
        push('(');
        else if(exp[i]=='^' || exp[i]=='+' || exp[i]=='-' || exp[i]=='/' || exp[i]=='*' )
        {
            if(stack[top]=='(' || precedence(exp[i])>precedence(stack[top]))
                push(exp[i]);
            else {
            while(precedence(stack[top])>=precedence(exp[i])) {
                if(stack[top]!='(') {
                printf("%c",stack[top]);
                pop();
                }
                else
                break;
            }
          }
        }
        else if(exp[i]==')')
        {
            while(stack[top]!='(') {
                    printf("%c",stack[top]);
                    pop();
            }
        pop();
        }

i++;
}
}

int main() {
char in_arr[20];
printf("\nEnter infix expression to be evaluated\t");
gets(in_arr);
inftopost(in_arr);
printf("\n");
return 1;
}
