// https://www.acmicpc.net/problem/23323
// 2021-11-02 00:24:33 D
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<long long> dp(64, 1);
    for(int i=1; i<64; i++) dp[i]=dp[i-1]*2;

    while(t--)
    {
        long long n,m; scanf("%lld%lld", &n,&m);
        int cnt=0;
        while(n!=0) n/=2, cnt++;
        printf("%lld\n", cnt+m);
    }
}

/*

*/