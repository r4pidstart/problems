// https://www.acmicpc.net/problem/2523
// 2022-03-09 18:53:44 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
    for(int i=n-1; i>=1; i--)
    {
        for(int j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
}

/*
    
*/