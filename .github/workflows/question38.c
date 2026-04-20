#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

void initDeque(struct Deque* dq) {
    dq->front = dq->rear = NULL;
}

void push_front(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (dq->front == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void push_back(struct Deque* dq, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (dq->rear == NULL) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

void pop_front(struct Deque* dq) {
    if (dq->front == NULL) return;
    struct Node* temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
}

void pop_back(struct Deque* dq) {
    if (dq->rear == NULL) return;
    struct Node* temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
}

int front(struct Deque* dq) {
    return (dq->front != NULL) ? dq->front->data : -1;
}

int back(struct Deque* dq) {
    return (dq->rear != NULL) ? dq->rear->data : -1;
}

int main() {
    struct Deque dq;
    initDeque(&dq);
    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);
    pop_front(&dq);
    printf("%d %d\n", front(&dq), back(&dq));
    return 0;
}
