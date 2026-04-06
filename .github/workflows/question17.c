#include <stdio.h>
void findMaxMin(int n) 
{
    if (n <= 0) return;
    int current;
    scanf("%d", &current);
    int max = current;
    int min = current;
    for (int i = 1; i < n; i++) 
    {
        scanf("%d", &current);
        if (current > max) 
        {
            max = current;
        }
        if (current < min) 
        {
            min = current;
        }
    }
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}
int main() 
{
    int n;
    if (scanf("%d", &n) == 1) 
    {
        findMaxMin(n);
    }
    return 0;
}
