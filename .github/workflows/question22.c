#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
int countNodes(struct Node* head) 
{
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() 
{
    int n, val;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printf("%d\n", countNodes(head));
    return 0;
}
