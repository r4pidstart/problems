// https://www.acmicpc.net/problem/2533
// 2021-05-18 23:30:47 1672ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dest, dp;

int dfs(int prev, int now, int checked)
{
    if(dp[now][checked] != -1)
        return dp[now][checked];

    dp[now][checked]=checked;

    for(int next : dest[now])
    {
        if(prev==next)  continue;
        if(checked==0)
            dp[now][0]+=dfs(now, next, 1);
        else
            dp[now][1]+=min(dfs(now, next, 1), dfs(now, next, 0));
    }
    return dp[now][checked];
}   

int main(void)
{
    int n; scanf("%d", &n);
    dest.assign(n+1, vector<int>()), dp.assign(n+1, vector<int>(2, -1));
    // first-early adoptor
    for(int i=1; i<n; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        dest[a].push_back(b);
        dest[b].push_back(a);
    }
    printf("%d", min(dfs(0, 1, 0), dfs(0, 1, 1)));
}