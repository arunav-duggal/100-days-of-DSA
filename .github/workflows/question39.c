#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[10001];
int size = 0;

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) 
{
    size++;
    heap[size] = x;
    int curr = size;
    while (curr > 1 && heap[curr / 2] > heap[curr]) {
        swap(&heap[curr / 2], &heap[curr]);
        curr = curr / 2;
    }
}

int extractMin() 
{
    if (size == 0) return -1;
    int minVal = heap[1];
    heap[1] = heap[size];
    size--;
    int curr = 1;
    while (2 * curr <= size) 
    {
        int left = 2 * curr;
        int right = 2 * curr + 1;
        int smallest = left;
        if (right <= size && heap[right] < heap[left]) 
        {
            smallest = right;
        }
        if (heap[curr] <= heap[smallest]) break;
        swap(&heap[curr], &heap[smallest]);
        curr = smallest;
    }
    return minVal;
}

int peek() 
{
    if (size == 0) return -1;
    return heap[1];
}

int main() 
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    char op[20];
    while (n--) 
    {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) 
        {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) 
        {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) 
        {
            printf("%d\n", peek());
        }
    }
    return 0;
}
