// https://www.acmicpc.net/problem/1834
// 2023-08-08 01:42:03
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long sum=0;
    for(long i=1; i<n; i++)
        sum+=i*n+i;
    printf("%ld", sum);
}

/*
    
*/