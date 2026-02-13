#include <stdio.h>
int main() 
{
    int p, q, i, j;
    int log1[1000],log2[1000];
    scanf("%d",&p);
    for (i=0;i<p;i++) 
    {
        scanf("%d",&log1[i]);
    }
    scanf("%d",&q);
    for (j=0;j<q;j++) 
    {
        scanf("%d",&log2[j]);
    }
    int first=0,second=0;
    while (first<p && second<q) 
    {
        if (log1[first]<=log2[second]) 
        {
            printf("%d ",log1[first]);
            first++;
        } 
        else 
        {
            printf("%d ",log2[second]);
            second++;
        }
    }
    while (first<p) 
    {
        printf("%d ",log1[first++]);
    }
    while (second<q) 
    {
        printf("%d ",log2[second++]);
    }
    return 0;
}
