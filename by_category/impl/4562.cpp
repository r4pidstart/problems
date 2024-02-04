// https://www.acmicpc.net/problem/4562
// 2024-02-05 05:56:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    while(n--)
    {
        int a,b; scanf("%d%d", &a, &b);
        printf("%s BRAINS\n", a>=b ? "MMM":"NO");
    }
}

/*
    
*/