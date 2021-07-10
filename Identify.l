%{
    #include <stdio.h>
    int f;
%}
%% 
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short|unsigned return 1;
([a-zA-Z][0-9])+|[a-zA-Z]* return 2;
[0-9]+ return 3;
%%
void main() {
    while(f = yylex()) {
        if(f == 1) {
            printf("Keyword\n");
        }
        else if(f == 2) {
            printf("Identifier\n");
        }
        else {
            printf("Number\n");
        }
    }
}