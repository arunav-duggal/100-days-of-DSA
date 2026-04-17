#include <stdio.h>
#include <string.h>
#define MAX 1000
int pq[MAX];
int size = 0;
void insert(int x) 
{
    if (size >= MAX) return;
    int i = size - 1;
    while (i >= 0 && pq[i] < x) 
    {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    size++;
}

void delete() 
{
    if (size == 0) 
    {
        printf("-1\n");
    }
    else 
    {
        printf("%d\n", pq[--size]);
    }
}

void peek() 
{
    if (size == 0) 
    {
        printf("-1\n");
    } 
    else 
    {
        printf("%d\n", pq[size - 1]);
    }
}

int main() 
{
    int n, value;
    char op[10];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) 
        {
            scanf("%d", &value);
            insert(value);
        } 
        else if (strcmp(op, "delete") == 0) 
        {
            delete();
        } 
        else if (strcmp(op, "peek") == 0) 
        {
            peek();
        }
    }

    return 0;
}
