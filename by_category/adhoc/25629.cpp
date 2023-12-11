// https://www.acmicpc.net/problem/25629
// 2023-12-11 21:02:48
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int odd=0, even=0;
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        if(a&1) odd++;
        else even++;
    }

    printf("%d", odd==(n+1)/2 and even==n/2);
}

/*
    
*/