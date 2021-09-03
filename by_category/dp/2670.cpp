// https://www.acmicpc.net/problem/2670
// 2021-09-03 21:36:13 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<double> dp(n+1, 0);
    dp[0]=1;
    for(int i=1; i<=n; i++)
    {
        double tmp; scanf("%lf", &tmp);
        if(tmp*dp[i-1] > tmp) dp[i]=tmp*dp[i-1];
        else dp[i]=tmp;
        if(i==1 && tmp<1) dp[0]=0;
    }
    printf("%.3lf", *max_element(dp.begin(), dp.end()));
}

/*

*/