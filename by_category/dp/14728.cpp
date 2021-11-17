// https://www.acmicpc.net/problem/14728
// 2021-11-18 03:12:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,t; scanf("%d%d", &n,&t);
    vector<int> reqTime(n+1), value(n+1), dp(t+1);
    for(int i=0; i<n; i++) scanf("%d%d", &reqTime[i+1], &value[i+1]);
    for(int item=1; item<=n; item++)
        for(int i=t; i>0; i--)
            if(i >= reqTime[item])
                dp[i]=max(dp[i], dp[i-reqTime[item]]+value[item]);
    printf("%d", dp[t]);
}

/*
    
*/