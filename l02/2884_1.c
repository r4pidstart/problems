#include <stdio.h>

int main(void)
{   
    int H,M;
    scanf("%d %d", &H, &M);
    printf("%d %d", (H==0 && M<45) ? (23) : (M<45 ? (H-1):(H)), (M<45) ? (60-(45-M)):(M-45));
}