#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
int pop() 
{
    if (top == NULL) return 0;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}
int evaluatePostfix(char* exp) 
{
    for (int i = 0; exp[i] != '\0'; i++) 
    {
        if (exp[i] == ' ') continue;
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } 
        else 
        {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) 
            {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[100];
    scanf("%[^\n]s", exp);
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
