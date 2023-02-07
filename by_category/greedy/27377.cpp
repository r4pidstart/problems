// https://www.acmicpc.net/problem/27377
// 2023-02-08 02:27:36
#include"bits/stdc++.h"
#include <climits>
#include <cstdint>
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int T; scanf("%d", &T);
    while(T--)
    {
        long n, s, t;
        scanf("%ld%ld%ld", &n, &s, &t);

        __int128_t ans=LLONG_MAX;
        int cnt=0, flag=0;
        while(n)
        {
            if(n&1) flag++, n--;
            ans=min(ans, (__int128_t)t*cnt + (__int128_t)s*flag + (__int128_t)s*n);
            n/=2, cnt++;
        }
        assert(ans > 0);
        printf("%ld\n", (long)ans);
    }
}

/*
    
*/