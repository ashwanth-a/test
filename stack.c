#include<stdio.h>
int push(int s[],int top)
{
    if(top<9)
    {
        top++;
        printf("Enter the value to be pushed\n");
        scanf("%d",&s[top]);
    }
    else
    {
        printf("Stack Overflow\n");
    }
    return top;
}

int pop(int s[],int top)
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("The popped element is %d\n",s[top]);
        top--;
    }
    return top;
}

int peek(int s[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The topmost element is %d\n",s[top]);
    }
    return top;
}

int display(int s[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The elements in the stack are:\n");
        printf("|: :|\n");
        
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",s[i]);
        }
        printf("|: :|\n");
    }
    return top;
}


int main()
{
    int stack[10],top=-1,flag=1,choice;
    printf("Stack Operations using Array\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
    do
    {
        printf("Enter your choice:[1-5]: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top=push(stack,top);
                break;
            case 2:
                top=pop(stack,top);
                break;
            case 3:
                top=peek(stack,top);
                break;
            case 4:
                top=display(stack,top);
                break;
            case 5:
                flag=0;
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (flag);
   
 return 0;     




}