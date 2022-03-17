// https://www.acmicpc.net/problem/10991
// 2022-03-17 15:13:07 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n-i; j++)
            printf(" ");
        for(int j=0; j<=i; j++)
            printf("* ");
        printf("\n");
    }
}

/*
    
*/