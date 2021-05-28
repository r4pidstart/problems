// https://www.acmicpc.net/problem/2098
// 2021-05-29 04:05:31 0ms
#include<bits/stdc++.h>
using namespace std;

int n, ans;
vector<vector<int> > dp, cost;
int dfs(int mask, int now)
{
    if(mask == (1<<n)-1) // 모두 순회 했을 때
        return cost[now][0]!=0 ? cost[now][0] : INT32_MAX/2; // 길이 없을 수 있음
    if(dp[mask][now] != INT32_MAX/2) // 이미 방문 했을 때
        return dp[mask][now];

    bitset<16> b=mask;
    for(int i=0; i<n; i++)
        if(b[i]==0 && cost[now][i]!=0)
            dp[mask][now]=min(dp[mask][now], dfs(mask|(1<<i), i)+cost[now][i]);

    return dp[mask][now];
}

int main(void)
{
    scanf("%d", &n);
    dp.assign(1<<n, vector<int>(n, INT32_MAX/2)), cost.assign(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &cost[i][j]);
    printf("%d", dfs(1<<0,0));
    // 1->2->3->1과, 2->3->4->1은 같은 경우임.
}