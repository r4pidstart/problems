// https://www.acmicpc.net/problem/13301
// 2021-08-26 21:26:10 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long perimeter;
    int n; scanf("%d", &n);
    vector<long long> dp(n+1, 0);
    dp[1]=1, dp[2]=1;
    for(int i=3; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }

    if(n>2)
        perimeter=dp[n]*3+dp[n-1]*3+dp[n-2]*1;

    if(n==1) printf("4");
    else if(n==2) printf("6");
    else printf("%lld", perimeter);
}

/*

*/