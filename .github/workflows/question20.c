#include <stdio.h>
void countZeroSumSubarrays() 
{
    int n;
    if (scanf("%d", &n) != 1) return;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        long long current_sum = 0;
        for (int j = i; j < n; j++) 
        {
            current_sum += arr[j];
            if (current_sum == 0) 
            {
                count++;
            }
        }
    }
    printf("%d\n", count);
}
int main() 
{
    countZeroSumSubarrays();
    return 0;
}
