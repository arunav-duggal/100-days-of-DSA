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
int getLength(struct Node* head) 
{
    int len = 0;
    while (head) 
    {
        len++;
        head = head->next;
    }
    return len;
}
void findIntersection(struct Node* h1, struct Node* h2) 
{
    int l1 = getLength(h1);
    int l2 = getLength(h2);
    int d = abs(l1 - l2);
    struct Node *curr1 = h1, *curr2 = h2;
    if (l1 > l2) 
    {
        for (int i = 0; i < d; i++) curr1 = curr1->next;
    } else 
    {
        for (int i = 0; i < d; i++) curr2 = curr2->next;
    }
    while (curr1 && curr2) 
    {
        if (curr1->data == curr2->data)
        {
            printf("%d\n", curr1->data);
            return;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    printf("No Intersection\n");
}
struct Node* buildList(int n) 
{
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) head = tail = newNode;
        else { tail->next = newNode; tail = newNode; }
    }
    return head;
}
int main() 
{
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* h1 = buildList(n);
    if (scanf("%d", &m) != 1) return 0;
    struct Node* h2 = buildList(m);
    findIntersection(h1, h2);
    return 0;
}
