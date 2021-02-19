#include <stdio.h>

int main(void)
{   
    int H,M;
    scanf("%d %d", &H, &M);
    if(M<45)
    {
        if(H==00 || H==0)
        {
            printf("23 %d", 60-(45-M));
            return 0;
        }
        printf("%d %d", H-1, 60-(45-M));
    }
    else
    {
        if(H==00 || H==0)
        {
            printf("0 %d", M-45);
            return 0;
        }
        printf("%d %d", H, M-45);
    }
}