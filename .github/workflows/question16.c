#include <stdio.h>
void countFrequency(int n) 
{
    int arr[n];
    int visited[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }
    int first = 1;
    for (int i = 0; i < n; i++) 
    {
        if (visited[i] == 1) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                count++;
                visited[j] = 1;
            }
        }
        
        if (!first) printf(" ");
        printf("%d:%d", arr[i], count);
        first = 0;
    }
    printf("\n");
}
int main() 
{
    int n;
    if (scanf("%d", &n) == 1) 
    {
        countFrequency(n);
    }
    return 0;
}
