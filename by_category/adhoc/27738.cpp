// https://www.acmicpc.net/problem/27738
// 2024-03-11 23:41:13
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long n; scanf("%ld", &n);
    int a,b,c,d,e,f; scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    long ans=0;
    long i=0;
    if(n>=f)
        i=n/f*f+1;
    for(; i<=n; i++)
    {
        if(i%a==0)
            ans+=i;
        if(ans and i%b==0)
            ans%=i;
        if(i%c==0)
            ans&=i;
        if(i%d==0)
            ans^=i;
        if(i%e==0)
            ans|=i;
    }
    printf("%ld", ans);
}

/*
    
*/