// https://www.acmicpc.net/problem/25304
// 2022-08-11 05:47:10
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int sum,n; scanf("%d%d", &sum, &n);
    while(n--)
    {
        int a,b; scanf("%d%d", &a, &b);
        sum-=a*b;
    }
    printf("%s", sum ? "No":"Yes");
}

/*
    
*/