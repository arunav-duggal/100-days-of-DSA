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
struct Node* deleteKey(struct Node* head, int key) 
{
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) 
    {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}
void printList(struct Node* head) 
{
    while (head) 
    {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}
int main() 
{
    int n, val, key;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &key);
    head = deleteKey(head, key);
    printList(head);
    return 0;
}
