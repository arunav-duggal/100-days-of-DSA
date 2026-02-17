#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    if (scanf("%d",&n)!=1||n<=0) return 0;

    int *arr=(int *)malloc(n * sizeof(int));
    for (int i=0;i<n;i++) 
    {
        scanf("%d", &arr[i]);
    }
    int slow=0;
    for (int fast=1;fast<n;fast++) 
    {
        if (arr[fast]!=arr[slow]) 
        {
            slow++;
            arr[slow]=arr[fast];
        }
    }
    for (int i = 0; i <= slow; i++) 
    {
        printf("%d%c", arr[i], (i == slow ? '\n' : ' '));
    }
    free(arr);
    return 0;
}
