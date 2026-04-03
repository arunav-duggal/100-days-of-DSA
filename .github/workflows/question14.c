#include <stdio.h>
#include <stdbool.h>
void checkIdentity(int n) 
{
    int val;
    bool isIdentity = true;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &val);
            if (i == j) 
            {
                if (val != 1) isIdentity = false;
            } else 
            {
                if (val != 0) isIdentity = false;
            }
        }
    }
    if (isIdentity) 
    {
        printf("Identity Matrix\n");
    } else 
    {
        printf("Not an Identity Matrix\n");
    }
}
int main() 
{
    int n;
    if (scanf("%d", &n) == 1) 
    {
        checkIdentity(n);
    }
    return 0;
}
