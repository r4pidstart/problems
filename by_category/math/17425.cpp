// https://www.acmicpc.net/problem/17425
// 2022-02-16 23:40:45 120ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<long long> dp(1000001);
    for(int i=1; i<1000001; i++)
        for(int j=i; j<1000001; j+=i)
            dp[j]+=i;
    for(int i=1; i<1000001; i++)
        dp[i]+=dp[i-1];
    while(t--)
    {
        int i; scanf("%d", &i);
        printf("%lld\n", dp[i]);
    }
}

/*
    
*/