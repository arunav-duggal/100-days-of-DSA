#include <stdio.h>

long long power(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * power(a, b - 1);
    }
}

int main() {
    int base, exp;
    if (scanf("%d %d", &base, &exp) == 2) {
        printf("%lld\n", power(base, exp));
    }
    return 0;
}
