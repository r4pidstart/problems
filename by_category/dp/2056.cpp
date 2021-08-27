// https://www.acmicpc.net/problem/2056
// 2021-08-28 02:45:38 80ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> dp(n,0);
    for(int i=0; i<n; i++)
    {
        int c,m; scanf("%d%d", &c, &m);
        int min_time=0, ans=0;
        for(int j=0; j<m; j++)
        {
            int subtask; scanf("%d", &subtask);
            min_time=max(min_time, dp[subtask-1]);
        }
        dp[i]=min_time+c;
    }
    printf("%d", *max_element(dp.begin(), dp.end()));
}

/*

*/