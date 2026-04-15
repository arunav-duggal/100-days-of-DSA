#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) 
    {
        front = rear = newNode;
    } 
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}
void display() 
{
    struct Node* temp = front;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL) 
        {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    int n, value;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(value);
        }
    }
    display();
    return 0;
}
