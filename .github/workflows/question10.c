#include <stdio.h>
#include <string.h>

const char* is_palindrome(char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return "NO";
        }
        left++;
        right--;
    }
    return "YES";
}

int main() {
    char s[100];
    if (scanf("%99s", s) == 1) {
        printf("%s\n", is_palindrome(s));
    }
    return 0;
}
