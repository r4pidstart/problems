// https://www.acmicpc.net/problem/3474
// 2023-05-04 00:28:36
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        int cnt=0;
        while(n) cnt+=n/5, n/=5;
        printf("%d\n", cnt);
    }
}

/*
    
*/