// https://www.acmicpc.net/problem/4233
// 2022-12-21 01:00:08          
#include"bits/stdc++.h"
using namespace std;

int powmod(int a, int p, int mod)
{
    if(p==0)
        return 1;
    else if(p==1)
        return a;
    
    long tmp=powmod(a, p/2, mod);
    tmp=(tmp*tmp) % mod;
    
    if(p&1)
        tmp*=a;
    return tmp%mod;
}

int main(void)
{
#ifdef LOCAL
#endif
    while(true)
    {
        int p,a; scanf("%d%d", &p, &a);
        if(p==0 and a==0)
            break;
        
        int flag=0;
        for(int i=2; i*i <= p; i++)
            if(p%i == 0) flag=1;

        // a^p == a (mod p)
        if(flag and powmod(a, p, p) == a)
            printf("yes\n");
        else
            printf("no\n");
    }
}

/*
    
*/