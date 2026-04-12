#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int stack[MAX];
int top = -1;
void push(int value) 
{
    if (top < MAX - 1) 
    {
        stack[++top] = value;
    }
}
void pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
    } else 
    {
        printf("%d\n", stack[top--]);
    }
}
void display() 
{
    if (top != -1) 
    {
        for (int i = top; i >= 0; i--) 
        {
            printf("%d%c", stack[i], (i == 0 ? '\n' : ' '));
        }
    }
}
int main() 
{
    int n, choice, value;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) 
        {
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) 
        {
            pop();
        } else if (choice == 3) 
        {
            display();
        }
    }
    return 0;
}
