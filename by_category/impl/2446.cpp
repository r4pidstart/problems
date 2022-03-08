// https://www.acmicpc.net/problem/2446
// 2022-03-08 19:39:01 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<n-i; j++)
            printf(" ");
        for(int j=0; j<2*i-1; j++)
            printf("*");
        // for(int j=0; j<n-i; j++)
        //     printf(" ");
        printf("\n");
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<n-i; j++)
            printf(" ");
        for(int j=0; j<2*i-1; j++)
            printf("*");
        // for(int j=0; j<n-i; j++)
        //     printf(" ");
        printf("\n");
    }
}

/*
    
*/