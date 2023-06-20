#include<cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    while(n/5)printf("V"),n-=5;
    while(n--)printf("I");
}