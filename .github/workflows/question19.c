#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int compare(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}
void findClosestToZero() 
{
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    int l = 0, r = n - 1;
    int min_sum = INT_MAX;
    int res_l = 0, res_r = n - 1;
    while (l < r) 
    {
        int sum = arr[l] + arr[r];
        if (abs(sum) < abs(min_sum)) 
        {
            min_sum = sum;
            res_l = l;
            res_r = r;
        }
        if (sum < 0) l++;
        else r--;
    }
    printf("%d %d\n", arr[res_l], arr[res_r]);
}
int main() 
{
    findClosestToZero();
    return 0;
}
