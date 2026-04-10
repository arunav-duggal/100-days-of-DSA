#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() 
{
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) 
        {
            head = newNode;
            newNode->next = head;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
    if (head != NULL) 
    {
        struct Node* temp = head;
        do 
        {
            printf("%d%s", temp->data, (temp->next != head ? " " : ""));
            temp = temp->next;
        } 
        while (temp != head);
        printf("\n");
    }
    return 0;
}
