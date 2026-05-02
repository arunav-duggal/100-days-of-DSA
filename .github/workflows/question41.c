#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            int val;
            scanf("%d", &val);
            enqueue(q, val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
