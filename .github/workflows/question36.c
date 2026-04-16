#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
void enqueue(int value) 
{
    if ((rear + 1) % SIZE == front) 
    {
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}
int dequeue() 
{
    if (front == -1) 
    {
        return -1;
    }
    int item = queue[front];
    if (front == rear) 
    {
        front = rear = -1;
    } else 
    {
        front = (front + 1) % SIZE;
    }
    return item;
}
void display() 
{
    if (front == -1) return;
    int i = front;
    while (1) {
        printf("%d", queue[i]);
        if (i == rear) break;
        printf(" ");
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() 
{
    int n, m, value;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) 
    {
        if (scanf("%d", &value) == 1) 
        {
            enqueue(value);
        }
    }
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) 
    {
        int temp = dequeue();
        if (temp != -1) 
        {
            enqueue(temp);
        }
    }
    display();
    return 0;
}
