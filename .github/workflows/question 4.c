#include <stdio.h>

void reverseArray(int n, int nums[]) {
    int left = 0;
    int right = n - 1;
    while (left < right) 
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}
int main() 
{
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) 
      scanf("%d", &nums[i]);
    reverseArray(n, nums);
    for (int i = 0; i < n; i++) 
    {
        printf("%d%s", nums[i], (i == n - 1) ? "" : " ");
    }
    return 0;
}
