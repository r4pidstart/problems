#include <stdio.h>

int main(void)
{
    int x, result[42]={0,}, n=0;
    for (int i=0; i<10; i++)
    {
        scanf("%d", &x);
        result[x%42]++;
    }
    for (int i=0; i<42; i++)
    {
        if(result[i] != 0)
            n++;
    }
    printf("%d", n);
}

// i;
// a[43];
// main(b)
// {
//     for(;~scanf("%d",&b);)
//         i+=!a[b%42]++;
//     printf("%d",i);
// }