     // https://www.acmicpc.net/problem/15717
// 2024-03-20 01:23:27
#include"bits/stdc++.h"
using namespace std;

long modpow(long a, long b)
{
    if(b==0)
        return 1;
    else if(b==1)
        return a;

    const int mod=1e9+7;
    long tmp=modpow(a, b/2);
    if(b&1)
        return tmp*tmp%mod*a%mod;
    return tmp*tmp%mod;
}

int main(void)
{
    long n; scanf("%ld", &n);
    if(n==0)
        printf("1");
    else
        printf("%ld", modpow(2, n-1));
}

/*
0
-> 1

1 
-> 
    1
    -> 1
2
->
    2
    1 1
    -> 2
3
-> 4
4
->
    4
    3 1
    1 3
    2 2
    2 1 1
    1 2 1
    1 1 2
    1 1 1 1
    -> 8
5
->
    5
    4 1
    1 4
    3 2
    2 3
    3 1 1
    1 3 1
    1 1 3
    2 2 1
    2 1 2
    1 2 2
    2 1 1 1
    1 2 1 1 
    1 1 2 1
    1 1 1 2
    1 1 1 1 1
    -> 16
*/