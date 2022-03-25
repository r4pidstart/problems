// https://www.acmicpc.net/problem/10995
// 2022-03-26 06:59:15 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n*2; j++)
            printf("%c", (j&1)!=(i&1) ? ' ':'*');
        printf("\n");
    }
}

/*
    
*/