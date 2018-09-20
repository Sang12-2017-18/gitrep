#include<stdio.h>
#include<stdlib.h> 
#define MAX 100  
void push(int *s,int ele,int *top);
int pop(int *s,int *top); 
void palin(int *s,int *top); 
void display(int *s,int top);
int main()
{
    int s[MAX],top=-1,ch,ele,c;
    while(1)
    { 
        printf("\nMENU\n1-Push into stack\n2-Pop from stack\n3-To check Palindrome\n4-Display status of stack\n5-Exit\nEnter your choice: "); 
        scanf("%d",&ch); 
        switch(ch)
        {
            case 1:printf("Enter element to be inserted: ");
                   scanf("%d",&ele); 
                   push(s,ele,&top);
                   break;
            case 2:c=pop(s,&top);
                   if(c!=-101)
                        printf("The deleted element is:%d\n",c);
                   break ;
            case 3:palin(s,&top);
                   break; 
            case 4:display(s,top); 
                   break;
            case 5:exit(0);
        } 
    } 
    return 0;
}

void push(int s[],int ele,int *top)
{
    if(MAX-1==*top)
    {
        printf("Overflow");
        return ;
    }
    s[++(*top)]=ele;
}

int pop(int s[],int *top)
{
    if(*top==-1)
    { 
        printf("Underflow ");  
        return -101;
    } 
    else
        return s[(*top)--];
} 

void display(int s[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return ;
    } 
    while(top!=-1)
    {
        printf("%d\n",s[top]);
        top--;
    }
}

void palin(int s[],int *top)
{
    *top=-1;                                       //clearing previous contents of stack 
    int A[MAX],m,i,B[MAX];
    printf("Enter the no of digits in number: ");
    scanf("%d",&m);
    printf("Enter the elements: ");
    for(i=0;i<m;i++)
       scanf("%d",&A[i]);
    for(i=0;i<m;i++)
       push(s,A[i],top);
    for(i=0;i<m;i++)
       B[i]=pop(s,top);
    for(i=0;i<m;i++)
       if(A[i]!=B[i])
       {
           printf("It is not a palindrome\n");
           return ;
       }
    printf("It is a palindrome\n");
}  
