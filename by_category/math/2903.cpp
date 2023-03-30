// https://www.acmicpc.net/problem/2903
// 2023-03-31 04:15:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    long ans=4;
    for(int i=0; i<n; i++)
        ans=ans*4-(1<<i)*4-4+1;
    printf("%ld", ans);
}

/*
    
*/