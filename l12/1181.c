#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct word
{
  char s[51];
  int l;
};

int comp(const void *v1, const void *v2)
{
    struct word *a = (struct word *)v1;
    struct word *b = (struct word *)v2;

    if(a->l < b->l)
        return -1;
    else if(a->l > b->l)
        return 1;
    else
        return (strcmp(a->s, b->s));
}

int main(void)
{
    int n;
    scanf("%d", &n);
    struct word test[n];
    for(int i=0; i<n; i++)
    {
        scanf("%s", test[i].s);
        test[i].l = strlen(test[i].s);
    }
    qsort(test, n, sizeof(struct word), comp);

    printf("%s\n", test[0].s);
    for(int i=1; i<n; i++)
    {
        if(strcmp(test[i-1].s, test[i].s))
            printf("%s\n", test[i].s);
    }
}
