// https://www.acmicpc.net/problem/9657
// 2021-09-05 22:18:13 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(n+1, 0);
    dp[1]=1, dp[3]=1, dp[4]=1;
    for(int i=5; i<=n; i++)
    {
        if(dp[i-1] && dp[i-3] && dp[i-4]) // 내가 뽑을 수 있는 경우가 모두 상대를 이기게 만들 경우
            dp[i]=0;
        else
            dp[i]=1;
    }
    if(dp[n]) printf("SK");
    else printf("CY");
}

/*

*/