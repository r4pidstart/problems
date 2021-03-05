#include <stdio.h>

int main(void)
{
    int n, y=0;
    scanf("%d", &n);
    char arr[n];
    scanf("%s", arr);
    for (int i=0; i<n; i++)
        y+=arr[i]-48;
    printf("%d", y);
}