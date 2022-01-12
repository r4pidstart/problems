// https://www.acmicpc.net/problem/23977
// 2022-01-13 03:23:07 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int k,n;
    long long ans=1; scanf("%d%d", &k,&n);
    for(int i=0; i<n; i++)
    {
        int t; scanf("%d", &t);
        ans=lcm(t, ans);
    }
    printf("%lld", ans-k);
}

/*

*/