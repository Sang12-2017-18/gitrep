//2.Design, Develop and Implement a Program in C for the following  operations on strings:

    //a.Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)

    //b.Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. 
    //  Report suitable messages in case PAT does not exist in STR. Support the program with functions for each of the 
    //  above operations. Don't use built-in functions.
#include<stdio.h>

void findRep(char STR[],char *,char *,char *); 
int  strLen(char *); 

int main()
{
   char STR[100],PAT[50],REP[50],OUT[100]; 
   printf("Enter main string: ");
   scanf("%[^\n]s",STR);
   printf("Enter pattern string: ");
   scanf("%s",PAT); 
   findRep(STR,PAT,REP,OUT);
   return 0;
} 

void findRep(char STR[],char PAT[],char REP[],char OUT[])
{
   int i,j,k,l=0,m=0,n=0,count;
   int pos[100]; 
   char c; 
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
        if(count==strLen(PAT))  
        {
            n++; 
            pos[m]=i;
            m++; 
        }
   }
   OUT[l]='\0'; 
   if(!n)
        printf("Pattern doesn't exist\n");
   else
   {
        printf("No of occurrences:%d\nThe positions are: ",n);   
        for(i=0;i<m;i++)
             printf("%d ",pos[i]);
        pos[i]=-1; 
        printf("\n");
        printf("Do you want to replace: ");
        scanf(" %c",&c); 
        if(c=='y')
        {
             j=0; 
             l=0; 
             printf("Enter the replacement string: ");
             scanf("%s",REP);
             for(i=0;STR[i]!='\0';i++)
             {
                  if(i==pos[j]) 
                  {
                      for(k=0;REP[k]!='\0';k++)
                      {
                          OUT[l]=REP[k];
                          l++; 
                      }
                      i+=strLen(PAT)-1;
                      j++; 
                  } 
                  else
                  {
                      OUT[l]=STR[i];
                      l++; 
                  }     
             }
        }
   }
   OUT[l]='\0';
   printf("The output string is:%s\n",OUT);        
}

int strLen(char str[])
{
   int i;
   for(i=0;str[i]!='\0';i++);
   return i;
}   
