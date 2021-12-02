// https://www.acmicpc.net/problem/6064
// 2021-12-03 01:46:37 120ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int m,n,x,y; scanf("%d%d%d%d", &m,&n,&x,&y);
        long long ans=y, a=(y-1)%m, limit=lcm(m,n);
        while(ans<=limit)
        {
            if(a+1==x)
                break;
            ans+=n;
            a=(a+n)%m;
        }
        if(a+1==x) printf("%lld\n", ans);
        else printf("-1\n");
    }
}

/*
    
*/