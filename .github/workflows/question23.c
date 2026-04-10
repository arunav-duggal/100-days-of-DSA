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
struct Node* buildList(int count) 
{
    if (count <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < count; i++) 
    {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head)
        {
            head = tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
struct Node* mergeLists(struct Node* l1, struct Node* l2) 
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (l1 && l2) 
    {
        if (l1->data <= l2->data) 
        {
            tail->next = l1;
            l1 = l1->next;
        } else 
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
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
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* l1 = buildList(n);
    if (scanf("%d", &m) != 1) return 0;
    struct Node* l2 = buildList(m);
    struct Node* mergedHead = mergeLists(l1, l2);
    printList(mergedHead);
    return 0;
}
