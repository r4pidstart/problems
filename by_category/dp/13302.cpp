// https://www.acmicpc.net/problem/13302
// 2021-09-15 00:03:10 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> day(n+1,1);
    for(int i=0; i<m; i++)
    {
        int a; scanf("%d", &a);
        day[a]=0;
    }

    vector<vector<int> > dp(n+1, vector<int>(50,INT32_MAX/2));
    // dp[i][j] : i일까지 j개의 쿠폰을 가지고 있으면서 리조트를 이용하는 최소비용
    dp[0][0]=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<50; j++)
        {
            if(dp[i][j]==INT32_MAX/2) continue;
            // 이용 안 하는 날
            if(!day[i+1])
                dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
            // 쿠폰 사용
            if(j>2)
                dp[i+1][j-3]=min(dp[i+1][j-3], dp[i][j]);
            // 하루 이용
            dp[i+1][j]=min(dp[i+1][j], dp[i][j]+10000);
            // 3일 이용
            if(i+3<=n)
                dp[i+3][j+1]=min(dp[i+3][j+1], dp[i][j]+25000);
            // 5일 이용
            if(i+5<=n)
                dp[i+5][j+2]=min(dp[i+5][j+2], dp[i][j]+37000);
        }
    printf("%d", *min_element(dp[n].begin(), dp[n].end()));
}

/*

*/