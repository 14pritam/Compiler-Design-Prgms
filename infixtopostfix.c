
#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;
void post(char infix[]);
void push(char);
char pop();

void main()
{
    char infix[25];
    printf("\nENTER THE INFIX EXPRESSION = ");
    gets(infix);
    post(infix);
    getch();
}

void push(char symb)
{
    if(top>=49)
    {
          printf("\nSTACK OVERFLOW");
         getch();
         return;
    }
    else
    {
          top=top+1;
         stack[top]=symb;
    }
}
char pop()
{
     char item;
     if(top==-1)
     {
            printf("\nSTACK IS EMPTY");
            getch();
            return(0);
      }
      else
     {
            item=stack[top];
            top--;
     }
     return(item);
}
int preced(char ch)
{
      if(ch==47)
      {
             return(5);
      }
      else if(ch==42)
      {
            return(4);
      }
      else if(ch==43)
      {
             return(3);
      }
      else
      return(2);
}
void post(char infix[])
{
      int l;
      int index=0,pos=0;
      char symbol,temp;
      char postfix[40];
      l=strlen(infix);
      push('#');
      while(index<l)
      {
             symbol=infix[index];
             switch(symbol)
             {
                    case '(': push(symbol);
                    break;
                    case ')': temp=pop();
                    while(temp!='(')
                    {
                            postfix[pos]=temp;
                            pos++;
                            temp=pop();
                    }
                    break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                    while(preced(stack[top])>=preced(symbol))
                    {
                            temp=pop();
                            postfix[pos]=temp;
                            pos++;
                    }
                    push(symbol);
                    break;
                    default: postfix[pos++]=symbol;
                    break;
            }
            index++;
      }
      while(top>0)
      {
               temp=pop();
               postfix[pos++]=temp;
      }
       postfix[pos++]='\0';
       puts(postfix);
       return;
}


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
