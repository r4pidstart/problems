// https://www.acmicpc.net/problem/17404
// 2021-05-29 23:11:03 0ms
#include<bits/stdc++.h>
using namespace std;

int n; 
vector<vector<int> > cost;
vector<vector<vector<int> > > memo;

int dp(int now, int index, int start)
{
    if(index==n-1) // 마지막 도달
    {
        if(now==start)
            return INT32_MAX/2;
        else
            return cost[index][now];
    }
    if(memo[index][start][now] != INT32_MAX/2)
        return memo[index][start][now];

    for(int i=0; i<3; i++)
        if(i != now)
            memo[index][start][now]=min(memo[index][start][now], dp(i, index+1, start)+cost[index][now]);

    return memo[index][start][now];
}

int main(void)
{
    scanf("%d", &n);
    cost.assign(n, vector<int>(3));
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            scanf("%d", &cost[i][j]);
    memo.assign(n, vector<vector<int> >(3, vector<int>(3, INT32_MAX/2)));
    printf("%d", min({dp(0,0,0), dp(1,0,1), dp(2,0,2)}));
}