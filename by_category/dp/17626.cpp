// https://www.acmicpc.net/problem/17626
// 2021-08-30 02:09:57 24ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(n+1, INT32_MAX/2), squares;
    dp[0]=0;
    for(long long i=1; i<=n; i++)
    {
        if(i*i <= n) squares.push_back(i*i);
        for(int it : squares)
            if(i-it >= 0)
                dp[i]=min(dp[i], dp[i-it]+1);
    }
    printf("%d", dp[n]);
}

/*
      
*/