// https://www.acmicpc.net/problem/16946
// 2024-06-06 23:23:57
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        for(int j=0; j<m; j++)
            table[i][j]=s[j]-'0';
    }

    vector<int> cnt(1);
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    vector<vector<int> > component(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(!table[i][j] and !component[i][j])
            {
                int target=cnt.size();
                cnt.push_back(1);

                queue<pair<int, int> > q;
                q.push({i, j});
                component[i][j]=target;

                while(q.size())
                {
                    auto [x, y]=q.front();
                    q.pop();

                    for(int w=0; w<4; w++)
                    {
                        int nx=x+way[w][0], ny=y+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<m and !table[nx][ny] and !component[nx][ny])
                            component[nx][ny]=target, q.push({nx, ny}), cnt[target]++;
                    }
                }
            }
        }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int ans=0;
            if(table[i][j])
            {
                ans=1;
                set<int> se;
                for(int w=0; w<4; w++)
                {
                    int nx=i+way[w][0], ny=j+way[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m)
                    {
                        int comp_idx=component[nx][ny];
                        if(se.find(comp_idx) == se.end())
                            ans+=cnt[comp_idx], se.insert(comp_idx);
                    }
                }
            }
            cout << ans%10;
        }
        cout << '\n';
    }
}

/*
    
*/