#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int n,s; scanf("%d%d", &n, &s);
    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    char str[200001];
    scanf("%s", str);
    size_t len=strlen(str);
    while(len--)
        printf("%c", str[len]);
}

/*

*/