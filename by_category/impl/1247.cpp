// https://www.acmicpc.net/problem/1247
// 2022-05-28 03:45:43 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    for(int i=0; i<3; i++)
    {
        int n; scanf("%d", &n);
        __int128_t ans=0;
        while(n--)
        {
            long long a; scanf("%lld", &a);
            ans+=a;
        }
        printf("%c\n", ans ? (ans < 0 ? '-':'+'):'0');
    }
}

/*
    
*/