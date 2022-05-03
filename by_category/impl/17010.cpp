// https://www.acmicpc.net/problem/17010
// 2022-05-04 03:16:42 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        int a,b; scanf("%d %c", &a, &b);
        while(a--)
            printf("%c", b);
        printf("\n");
    }
}

/*
    
*/