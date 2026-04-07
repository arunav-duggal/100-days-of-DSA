#include <stdio.h>
void reverse(int arr[], int start, int end) 
{
    while (start < end) 
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateArray() 
{
    int n, k;
    if (scanf("%d", &n) != 1) return;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d", &k) != 1) return;
    k = k % n;
    if (k == 0) goto print;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
print:
    for (int i = 0; i < n; i++) 
    {
        printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
    }
    printf("\n");
}
int main() 
{
    rotateArray();
    return 0;
}
