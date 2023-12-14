// https://www.acmicpc.net/problem/2547
// 2023-12-14 23:42:47
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
        __int128_t sum=0;
        for(int i=0; i<n; i++)
        {
            long a; scanf("%ld", &a);
            sum+=a;
        }
        printf("%s\n", sum%n==0 ? "YES":"NO");
    }
}

/*
    
*/