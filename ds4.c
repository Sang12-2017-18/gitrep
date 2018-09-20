#include<stdio.h>
#include<string.h>
#include<ctype.h> 
int pref(char c)
{
   if(c=='^')
       return 4;
   else if(c=='*' || c=='/' || c=='%')
       return 3;
   else if(c=='+' || c=='-')
       return 2;
   else
       return 1;
}
int main()
{
  char b[80],stack[80],post[100];
  int top=-1,i=0,j=0 ;
  char c[80]; 
  printf("Enter infix expression: ");
  scanf("%s",c);
  strcpy(b,"(");
  strcat(b,c);
  strcat(b,")"); 
  while(b[i]!='\0')
  {
      if(b[i]=='(')
         stack[++top]=b[i];  
      else if(isalnum(b[i])) 
         post[j++]=b[i]; 
      else if(b[i]==')')
      {
          while(stack[top]!='(')
               post[j++]=stack[top--];
          top--; //to remove open bracket 
      }
      else
      {
         while(pref(stack[top])>=pref(b[i]))
             post[j++]=stack[top--];
         stack[++top]=b[i];
      }
      i++;
  }
  post[j]='\0';
  printf("Postfix expression:%s\n",post);
  return 0;
}
