// https://www.acmicpc.net/problem/2842
// 2024-06-03 21:02:17
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
    vector<vector<char> > table(n, vector<char>(n));
    vector<vector<int> > height(n, vector<int>(n));

    pair<int, int> s;
    vector<pair<int, int> > house;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin >> table[i][j];
            if(table[i][j]=='P')
                s={i, j};
            else if(table[i][j]=='K')
                house.push_back({i, j});
        }
    
    vector<int> arr;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> height[i][j], arr.push_back(height[i][j]);
    int h_min=height[s.first][s.second], h_max=height[s.first][s.second];
    for(auto [x, y] : house)
        h_min=min(h_min, height[x][y]), h_max=max(h_max, height[x][y]);

    sort(arr.begin(), arr.end());

    int lo=0, hi=0, ans=INT32_MAX;
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(hi<n*n)
    {
        vector<vector<int> > visited(table.size(), vector<int>(table.size()));
        queue<pair<int, int> > q;
        if(arr[lo]<=height[s.first][s.second] and height[s.first][s.second]<=arr[hi])
        {
            q.push(s);
            visited[s.first][s.second]=1;
        }

        int cnt=0;
        while(q.size())
        {
            auto [x, y]=q.front();
            q.pop();

            if(table[x][y]=='K') cnt++;

            for(int w=0; w<8; w++)
            {
                int nx=x+way[w][0], ny=y+way[w][1];
                if(0<=nx and nx<table.size() and 0<=ny and ny<table.size() and arr[lo]<=height[nx][ny] and height[nx][ny]<=arr[hi] and !visited[nx][ny])
                    q.push({nx, ny}), visited[nx][ny]=1;                
            }
        }

        if(cnt==house.size())
            ans=min(ans, arr[hi]-arr[lo]), lo++;
        else
            hi++;
    }

    cout << ans;
}

/*
    
*/