// https://www.acmicpc.net/problem/24500
// 2023-12-16 22:50:06
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    long n; scanf("%ld", &n);

    if(n==1)
        return !printf("1\n1");
    for(int bit=0; bit<64; bit++)
    {
        unsigned long target=1UL<<bit;
        if(target-1 == n)
            return !printf("1\n%lu\n", n);
        
        if(target<=n and n<target*2-1) 
            return !printf("2\n%lu\n%lu\n", (~n)&(target-1), n);
    }
}

/*
    
*/