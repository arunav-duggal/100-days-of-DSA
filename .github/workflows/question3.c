#include <stdio.h>

int main() {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    } 
    if (scanf("%d", &k) != 1) return 0;
    int comparisons = 0;
    int found_index = -1;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (nums[i] == k) {
            found_index = i;
            break;
        }
    }
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);
    return 0;
}
