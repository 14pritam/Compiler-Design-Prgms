#include<stdio.h>
#include<ctype.h>
void FIRST(char[],char );
void addToResultSet(char[],char);
void RemFromResultSet(char[],char);
int numOfProductions;
char productionSet[10][10];
main()
{
    int i;
    char choice;
    char c;
    char result[20];
    printf("How many number of productions ? :");
    scanf(" %d",&numOfProductions);
    for(i=0;i<numOfProductions;i++)
    {
        printf("Enter productions Number %d : ",i+1);
        scanf(" %s",productionSet[i]);
    }
    do
    {
        printf("\n Find the FIRST of  :");
        fflush(stdin);
        scanf("%c",&c);

 FIRST(result,c);
        printf("\n FIRST(%c)= { ",c);
        for(i=0;result[i]!='\0';i++)
  printf(" %c ",result[i]);
        printf("}\n");
        printf("press 'y' to continue : ");
        scanf(" %c",&choice);
    }while(choice=='y'||choice =='Y');
}

void FIRST(char* Result,char c)
{
    int i,j,k;
    char subResult[20];
    int foundEpsilon;
    subResult[0]='\0';
    Result[0]='\0';

    if(!(isupper(c)))
    {
        addToResultSet(Result,c);
        return ;
    }

    for(i=0;i<numOfProductions;i++)
    {

        if(productionSet[i][0]==c)
        {
   if(productionSet[i][2]=='#') addToResultSet(Result,'#');

        else
             {
                    j=2;
                    while(productionSet[i][j]!='\0')
                     {
                 foundEpsilon=0;
                 FIRST(subResult,productionSet[i][j]);
                 for(k=0;subResult[k]!='\0';k++)
                      addToResultSet(Result,subResult[k]);
                  for(k=0;subResult[k]!='\0';k++)
                       if(subResult[k]=='#')
                       {
                           foundEpsilon=1;
                         break;
                       }



                    if(!foundEpsilon)
                      break;
                    j++;
                    }
      if(!foundEpsilon)
        RemFromResultSet(Result,'#');
      }
     }
 }

}

void addToResultSet(char Result[],char val)
{
    int k;
    for(k=0 ;Result[k]!='\0';k++)
        if(Result[k]==val)
            return;
    Result[k]=val;
    Result[k+1]='\0';
}

void RemFromResultSet(char Result[],char val)
{
    int i,k;
    for(k=0 ;Result[k]!='\0';k++)
        if(Result[k]==val)
         {
     for(i=k;Result[i]!='\0';i++)
                Result[i]=Result[i+1];
            break;
         }
}
// input:8
//S=AB
// B=aAB
// A=CD
// D=cCD
//  D=b
// C=(E)
// C=d
// B=b
