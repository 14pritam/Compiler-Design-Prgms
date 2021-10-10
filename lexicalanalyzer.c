
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main() {
    int op=0,id=0,cn=0;
    char operators[20],identifiers[20];
    int constants[20];
    char s[20];
    printf("\nEnter statement: ");
    scanf("%[^\n]s", s);

    for(int i=0;i<strlen(s) && s[i]!='\0';i++) {
            if(isspace(s[i]))
                continue;
            else if(isalpha(s[i])) {
                identifiers[id++] = s[i];
            }
            else if(isdigit(s[i])) {
                int b=0,factor=1,sum=0;
                char buff[5];
                buff[b++] = s[i];
                while(isdigit(s[i+1])) {
                    buff[b++] = s[++i];
                }
                if(b>1) {
                    factor=pow(10,b-1);
                }
            for(int j=0;j<b;j++) {
                int temp = buff[j]-'0';
                sum+=(temp*factor);
                factor/=10;
            }

                constants[cn++] = sum;
            }
            else if(s[i] == '+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='%') {
                operators[op++] = s[i];
            }
    }

    if(id!=0) {
        printf("\nIdentifiers are: ");
        for(int i=0;i<id;i++)
            printf("%c ",identifiers[i]);
    }
   if(op!=0) {
        printf("\nOperators are: ");
        for(int i=0;i<op;i++)
            printf("%c ",operators[i]);
    }
    if(cn!=0) {
        printf("\nConstants are: ");
        for(int i=0;i<cn;i++)
            printf("%d ",constants[i]);
    }
    printf("\n");
    return 0;
}

//input: a=10; b=+c+1;
