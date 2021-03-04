#include<stdio.h>
#include<stdlib.h>

struct people
{
  char s[101];
  int age;
};

int comp(const void *v1, const void *v2)
{
    struct people *a = (struct people *)v1;
    struct people *b = (struct people *)v2;

    if(a->age < b->age)
        return -1;
    else if(a->age > b->age)
        return 1;
    else
        return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    struct people test[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d%s", &test[i].age, test[i].s);
    }
    qsort(test, n, sizeof(struct people), comp);

    for(int i=0; i<n; i++)
    {
        printf("%d %s\n", test[i].age,test[i].s);
    }
}