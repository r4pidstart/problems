// https://www.acmicpc.net/problem/1949
// 2021-05-19 04:07:00 4ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > dest, dp;
vector<int> population;

int bfs(int prev, int now, int selected)
{
    if(dp[now][selected]!=-1)
        return dp[now][selected];
    
    dp[now][selected]=selected!=0 ? population[now] : 0;

    for(int next : dest[now])
    {
        if(next==prev)  continue;
        if(selected==0)
            dp[now][selected]+=max(bfs(now, next, 0), bfs(now, next, 1));
        else
            dp[now][selected]+=bfs(now, next, 0);
    }
    return dp[now][selected];
}

int main(void)
{
    int n; scanf("%d", &n);
    population.assign(n+1, 0), dest.assign(n+1, vector<int>()), dp.assign(n+1, vector<int>(2,-1));
    for(int i=1; i<=n; i++)
        scanf("%d", &population[i]);
    for(int i=0; i<n-1; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        dest[a].push_back(b);
        dest[b].push_back(a);
    }
    printf("%d", max(bfs(0, 1, 0), bfs(0, 1, 1)));
}

