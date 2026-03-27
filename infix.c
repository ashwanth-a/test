#include<stdio.h>
#include<string.h>
#define ma 100
char st[ma];
int top=-1;

void push(char X)
{
    st[++top]=X;
}
void pop()
{
    return st[top--];
}

int precedence(char X)
{
    if(X=='+' || X=='-')
        return 1;
    else if(X=='*' || X=='/')
        return 2;
    else
        return 0;
}

void infixtopostfix(char infix[], char postfix[])
{
    int k=0;
    for(int i=0; i<strelen(infix);i++)
    {
        char c = infix[i];
        if(c>='0' && c<='9')
        {
            postfix[k++]=c;
        }
        else if(c=='(')
        {
            push(c);
        }
        else if(c==')')
        {
            while(top!=-1 && st[top]!='(')
            {
                postfix[k++]=pop();
            }
            pop(); // Remove '(' from stack
        }
        else
        {
            while(top!=-1 && precedence(st[top])>=precedence(c))
            {
                postfix[k++]= pop();
            }
            push(c);
        }
    }
    while(top!=-1)
    {
        postfix[k++]=pop();
    }
}

void eval(char postfix[]);
{
    int val[ma],t=-1;
    for(int i =0; i<strlen(postfix); i++)
    {
        char c = postfix[i];
        if(c>='0' && c<='9')
        {
            val[++t]=c-'0'; // Convert char to int
        }
        else
        {
            int b=val[t--];
            int a=val[t--];
            switch(c)
            {
                case '+': val[++t]=a+b; break;
                case '-': val[++t]=a-b; break;
                case '*': val[++t]=a*b; break;
                case '/': val[++t]=a/b; break;
            }
        }
    }
    return val[t];
}

int main()
{
    char infix[ma], postfix[ma];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = eval(postfix);
    printf("Evaluated result: %d\n", result);
    return 0;
}