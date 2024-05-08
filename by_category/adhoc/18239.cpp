// https://www.acmicpc.net/problem/18239
// 2024-05-09 01:45:38
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    if(n==3)
        return !printf("NO");
    printf("YES\n");
    if(n==2)
    {
        for(int i=0; i<5; i++)
            printf("swap %d %d\n", 1, 2);
    }
    else if(k==1)
    {
        // 5 1 2 3 4
        printf("swap %d %d\n", 1, 2);
        // 1 5 2 3 4
        printf("reverse %d %d\n", 2, n);
        // 1 4 3 2 5
        printf("reverse %d %d\n", 2, n-1);
        // 1 2 3 4 5
        printf("swap 1 2\n");
        printf("swap 1 2\n");
    }
    else if(k==n-1)
    {
        // 2 3 4 5 1
        printf("swap %d %d\n", n-1, n);
        // 2 3 4 1 5
        printf("reverse %d %d\n", 1, n-1);
        // 1 4 3 2 5
        printf("reverse %d %d\n", 2, n-1);
        // 1 2 3 4 5
        printf("swap 1 2\n");
        printf("swap 1 2\n");
    }
    else
    {
        printf("reverse %d %d\n", 1, k);
        printf("reverse %d %d\n", k+1, n);
        printf("reverse %d %d\n", 1, n);
        printf("swap 1 2\n");
        printf("swap 1 2\n");
    }
}

/*
    
*/