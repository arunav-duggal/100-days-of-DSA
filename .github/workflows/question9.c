#include <stdio.h>
#include <string.h>

void mirror_name(char *s, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    mirror_name(s, start + 1, end - 1);
}

int main() {
    char code_name[100];
    if (scanf("%99s", code_name) == 1) {
        mirror_name(code_name, 0, strlen(code_name) - 1);
        printf("%s\n", code_name);
    }
    return 0;
}
