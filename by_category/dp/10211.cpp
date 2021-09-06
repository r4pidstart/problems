// https://www.acmicpc.net/problem/10211
// 2021-09-06 23:21:17 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> num(n+1, 0), dp(n+1, 0);
        for(int i=0; i<n; i++) 
            scanf("%d", &num[i+1]);
        
        for(int i=1; i<=n; i++)
            dp[i]=max(dp[i-1]+num[i], 0);

        int ans=*max_element(dp.begin(), dp.end());
        if(ans==0) ans=*max_element(num.begin()+1, num.end());
        
        printf("%d\n", ans);
    }
}

/*

*/