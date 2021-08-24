// https://www.acmicpc.net/problem/11060
// 2021-08-25 01:26:13 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> maze(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &maze[i]);

    vector<int> dp(n,0);
    queue<pair<int,int> > q;
    q.push({0, 0});
    while(!q.empty())
    {
        auto now=q.front(); q.pop();

        if(dp[now.first]) continue;
        dp[now.first]++;

        if(now.first == n-1)
        {
            printf("%d", now.second);
            return 0;
        }
        
        for(int i=1; i<=maze[now.first]; i++)
            if(now.first+i < n)
                q.push({now.first+i, now.second+1});
    }
    printf("-1");
}

/*

*/