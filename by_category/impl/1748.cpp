// https://www.acmicpc.net/problem/1748
// 2022-02-04 23:48:15 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m=10, digits=1; scanf("%d", &n);
    long long ans=0;

    while(true)
    {
        if(n/m) ans+=digits*(m-(m/10));
        else
        {
            ans+=digits*(n-(m/10)+1);
            break;
        }
        m*=10, digits++;
    }
    printf("%lld", ans);
}

/*
    
*/