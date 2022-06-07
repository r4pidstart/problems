// https://www.acmicpc.net/problem/24416
// 2022-06-08 04:49:42 184ms
#include"bits/stdc++.h"
using namespace std;

int fibo(int n)
{
    if(n==1 or n==2) return 1;
    return fibo(n-1)+fibo(n-2);
}
int main(void)
{
    int n; scanf("%d", &n);
    printf("%d %d", fibo(n), n-2);
}

/*
    
*/