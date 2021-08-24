// https://www.acmicpc.net/problem/14226
// 2021-08-25 01:15:22 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > dp(2001, vector<int>(2001, 0));
    queue<pair<int,pair<int,int> > > q;
    // 갯수, 클립보드, 횟수
    q.push({1, {0, 0}});

    while(!q.empty())
    {
        auto now=q.front(); q.pop();

        if(dp[now.first][now.second.first]) continue;
        dp[now.first][now.second.first]++;

        if(now.first==n)
        {
            printf("%d", now.second.second);
            return 0;
        }

        // 저장
        if(now.first != now.second.first && now.first != 0 && now.first < n)
            q.push({now.first, {now.first, now.second.second+1}});
        // 붙여넣기
        if(now.second.first != 0 && now.first < n)
            q.push({now.first+now.second.first, {now.second.first, now.second.second+1}});
        // 삭제
        if(now.first > 0 && now.first < n)
            q.push({now.first-1, {now.second.first, now.second.second+1}});
    }
}

/*

*/