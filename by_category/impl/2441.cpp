// https://www.acmicpc.net/problem/2441
// 2022-03-08 19:04:09 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=n; i>=0; i--)
    {
        for(int j=0; j<n-i; j++)
            printf(" ");
        for(int j=0; j<i; j++)
            printf("*");
        printf("\n");
    }
}

/*
    
*/