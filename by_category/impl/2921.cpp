// https://www.acmicpc.net/problem/2921
// 2023-11-04 01:01:05
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int cnt=0;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=i; j++)
            cnt+=i+j;
    printf("%d", cnt);
}

/*
    
*/