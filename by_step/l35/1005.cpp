// https://www.acmicpc.net/problem/1005
// 2021-06-05 11:58:08 232ms
#include<bits/stdc++.h>
using namespace std;

int dp(int now, vector<int>& cost, vector<vector<int> >& graph, vector<int>& memo)
{
    if(memo[now]!=-1)
        return memo[now];

    memo[now]=cost[now];
    for(int next : graph[now])
        memo[now]=max(memo[now], dp(next, cost, graph, memo)+cost[now]);
    return memo[now];
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n,&k);
        vector<int> cost(n+1), memo(n+1, -1);
        for(int i=1; i<=n; i++)
            scanf("%d", &cost[i]);
        vector<vector<int> > graph(n+1);
        for(int i=0; i<k; i++)
        {
            int a,b; scanf("%d%d", &a,&b);
            graph[b].push_back(a);
        }

        int target; scanf("%d", &target);
        printf("%d\n", dp(target, cost, graph, memo));
    }
}