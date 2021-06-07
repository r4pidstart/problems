#include<stdio.h>
#include<stdlib.h>

struct coordinate
{
  int x;
  int y; 
};

int comp_x(const void *v1, const void *v2)
{
    struct coordinate *a = (struct coordinate *)v1;
    struct coordinate *b = (struct coordinate *)v2;

    if(a->x < b->x)
        return -1;
    else if(a->x > b->x)
        return 1;
    else
        return 0;
}

int comp_y(const void *v1, const void *v2)
{
    struct coordinate *a = (struct coordinate *)v1;
    struct coordinate *b = (struct coordinate *)v2;

    if(a->y < b->y)
        return -1;
    else if(a->y > b->y)
        return 1;
    else
        return 0;
}

int comp(const void *v1, const void *v2)
{
    int tmp = comp_y(v1, v2);

    if(tmp !=0)
        return tmp;
    else
        return comp_x(v1, v2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    struct coordinate test[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &test[i].x, &test[i].y);
    }
    qsort(test, n, sizeof(struct coordinate), comp);

    for(int i=0; i<n; i++)
        printf("%d %d\n", test[i].x, test[i].y);
}