#include <stdio.h>
#include <stdlib.h>
void reverseQueue(int n, int queue[]) 
{
    int stack[n];
    int top = -1;
    for (int i = 0; i < n; i++) 
    {
        stack[++top] = queue[i];
    }
    for (int i = 0; i < n; i++) 
    {
        queue[i] = stack[top--];
    }
}
int main() 
{
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *queue = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    reverseQueue(n, queue);
    for (int i = 0; i < n; i++) 
    {
        printf("%d%s", queue[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
    free(queue);
    return 0;
}
