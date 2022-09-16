// https://www.acmicpc.net/problem/23814
// 2022-09-16 23:47:51 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    long tmp1=0, tmp2=0;
    long od,on,om,ok; scanf("%ld%ld%ld%ld", &od, &on, &om, &ok);
    // 1
    {
        long d=od, n=on, m=om, k=ok;
        if(d-n%d <= k)
        {
            k-=d-n%d;
            n+=d-n%d;
        }
        if(d-m%d <= k)
        {
            k-=d-m%d;
            m+=d-m%d;
        }
        if(tmp1 < n/d+m/d+k/d)
            tmp1=n/d+m/d+k/d, tmp2=max(tmp2, k);
    }
    //2
    {
        long d=od, n=on, m=om, k=ok;
        if(d-m%d <= k)
        {
            k-=d-m%d;
            m+=d-m%d;
        }
        if(d-n%d <= k)
        {
            k-=d-n%d;
            n+=d-n%d;
        }
        if(tmp1 <= n/d+m/d+k/d)
            tmp1=n/d+m/d+k/d, tmp2=max(tmp2, k);
    }
    // 3
    {
        long d=od, n=on, m=om, k=ok;
        if(d-m%d <= k)
        {
            k-=d-m%d;
            m+=d-m%d;
        }
        if(tmp1 <= n/d+m/d+k/d)
            tmp1=n/d+m/d+k/d, tmp2=max(tmp2, k);
    }
    // 4
    {
        long d=od, n=on, m=om, k=ok;
        if(d-n%d <= k)
        {
            k-=d-n%d;
            n+=d-n%d;
        }
        if(tmp1 <= n/d+m/d+k/d)
            tmp1=n/d+m/d+k/d, tmp2=max(tmp2, k);
    }
    // 5
    {
        long d=od, n=on, m=om, k=ok;
        if(tmp1 <= n/d+m/d+k/d)
            tmp1=n/d+m/d+k/d, tmp2=max(tmp2, k);
    }
    printf("%ld", tmp2);
}

/*
    
*/