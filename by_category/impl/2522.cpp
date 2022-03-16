// https://www.acmicpc.net/problem/2522
// 2022-03-16 00:34:29 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++) printf(" ");
        for(int j=0; j<=i; j++) printf("*");
        printf("\n");
    }
    for(int i=n-2; i>=0; i--)
    {
        for(int j=0; j<n-i-1; j++) printf(" ");
        for(int j=0; j<=i; j++) printf("*");
        printf("\n");
    }
}

/*
    
*/