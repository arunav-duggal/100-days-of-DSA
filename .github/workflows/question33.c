#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char item) 
{
    if (top < MAX - 1) 
    {
        stack[++top] = item;
    }
}
char pop() 
{
    if (top == -1) 
    {
        return -1;
    }
    return stack[top--];
}
int precedence(char symbol) 
{
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void infixToPostfix(char infix[]) 
{
    char postfix[MAX];
    int i, j = 0;
    char item, x;
    for (i = 0; infix[i] != '\0'; i++) 
    {
        item = infix[i];
        if (isalnum(item)) 
        {
            postfix[j++] = item;
        } 
        else if (item == '(') 
        {
            push(item);
        } 
        else if (item == ')') 
        {
            while ((x = pop()) != '(') 
            {
                postfix[j++] = x;
            }
        } 
        else 
        {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    while (top != -1) 
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("%s\n", postfix);
}
int main() 
{
    char infix[MAX];
  
    if (scanf("%s", infix) == 1) {
        infixToPostfix(infix);
    }
    return 0;
}
