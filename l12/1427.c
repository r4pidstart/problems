#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
  return( strcmp( (char *)b, (char *)a) );
}

int main(void)
{
    int n;
    char s[11]={0,};
    scanf("%d", &n);
    sprintf(s, "%d", n);
    qsort(s, strlen(s), sizeof(char), compare);
    printf("%s", s);
}