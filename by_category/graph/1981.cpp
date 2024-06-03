// https://www.acmicpc.net/problem/1981
// 2024-06-02 19:05:10
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> table[i][j];
    
    vector dp(n, vector(n, vector(201, INT32_MAX/2)));
    queue<tuple<int, int, int, int> > q;

    q.push({0, 0, table[0][0], table[0][0]});
    dp[0][0][table[0][0]]=0;

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x, y, mn, mx]=q.front();
        q.pop();

        if(dp[x][y][mn] < mx-mn) continue;
        
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<n)
            {
                int new_mn=min(mn, table[nx][ny]), new_mx=max(mx, table[nx][ny]);
                if(dp[nx][ny][new_mn] > new_mx-new_mn)
                    q.push({nx, ny, new_mn, new_mx}), dp[nx][ny][new_mn]=new_mx-new_mn;
            }
        }
    }
    cout << *min_element(dp[n-1][n-1].begin(), dp[n-1][n-1].end());
}

/*
    
*/