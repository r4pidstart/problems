// https://www.acmicpc.net/problem/30008
// 2023-11-04 00:38:27
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n, k; scanf("%d%d", &n, &k);
    while(k--)
    {
        int a; scanf("%d", &a);
        int t=a*100/n;
        if(t<=4)
            printf("1");
        else if(t<=11)
            printf("2");
        else if(t<=23)
            printf("3");
        else if(t<=40)
            printf("4");
        else if(t<=60)
            printf("5");
        else if(t<=77)
            printf("6");
        else if(t<=89)
            printf("7");
        else if(t<=96)
            printf("8");
        else
            printf("9");
        printf(" ");
    }
}

/*
    
*/