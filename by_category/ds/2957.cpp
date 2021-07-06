// https://www.acmicpc.net/problem/2957
// 2021-07-07 03:09:05 296ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    map<int, long long> m;
    long long n, c=0; scanf("%lld", &n);
    m[0]=-1, m[300001]=-1;
    while(n--)
    {
        int x; scanf("%d", &x);
        long long depth=max((--m.upper_bound(x))->second, m.upper_bound(x)->second)+1;
        m[x]=depth, c+=depth;
        printf("%lld\n", c);
    }
}

/*
    https://everenew.tistory.com/102
*/