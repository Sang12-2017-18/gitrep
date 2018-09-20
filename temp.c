//2.Design, Develop and Implement a Program in C for the following  operations on strings:

    //a.Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)

    //b.Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. 
    //  Report suitable messages in case PAT does not exist in STR. Support the program with functions for each of the 
    //  above operations. Don't use built-in functions.
#include<stdio.h>
void Findrep(char STR[],char *,char *,char *); 
int  STRLEN(char *); 
int main()
{
   char STR[80],PAT[50],REP[50],OUT[80]; 
   printf("Enter main string: ");
   scanf("%[^\n]s",STR);
   printf("Enter pattern string: ");
   scanf("%s",PAT);
   printf("Enter replacement string: ");
   scanf("%s",REP); 
   Findrep(STR,PAT,REP,OUT);
   return 0;
} 

void Findrep(char STR[],char PAT[],char REP[],char OUT[])
{
   int i,j,k,l=0,count;
   for(i=0;STR[i]!='\0';i++)
   {
        count=0;
        for(j=0;PAT[j]!='\0';j++)
        { 
             if(STR[i+j]==PAT[j])
                 count++;
             else
                 break ; 
        }
        if(count==STRLEN(PAT))  
        {
            for(k=0;REP[k]!='\0';k++)
            {
                OUT[l]=REP[k];
                l++;
            }
            i+=STRLEN(PAT)-1; 
        }
        else
        { 
            OUT[l]=STR[i];
            l++;
        }
   }
   OUT[l]='\0'; 
   printf("Output string is:%s\n",OUT);
}

int STRLEN(char str[])
{
   int i;
   for(i=0;str[i]!='\0';i++);
   return i;
}   
