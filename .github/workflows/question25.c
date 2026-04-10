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
int countOccurrences(struct Node* head, int key) 
{
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) 
    {
        if (curr->data == key) 
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}
int main() 
{
    int n, val, key;
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        if (n == 0) printf("0\n");
        return 0;
    }
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
    printf("%d\n", countOccurrences(head, key));
    return 0;
}
