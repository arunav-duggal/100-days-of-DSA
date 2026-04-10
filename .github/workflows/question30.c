#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int c, int e) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}
void printPolynomial(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        if (temp->exp == 0) 
        {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) 
        {
            printf("%dx", temp->coeff);
        } else 
        {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        temp = temp->next;
        if (temp != NULL) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}
int main() 
{
    int n, c, e;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d %d", &c, &e);
        struct Node* newNode = createNode(c, e);
        if (head == NULL) 
        {
            head = tail = newNode;
        } else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printPolynomial(head);
    return 0;
}
