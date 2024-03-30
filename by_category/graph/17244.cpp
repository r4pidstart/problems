// https://www.acmicpc.net/problem/17244
// 2024-03-29 22:09:44
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    swap(n,m);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    pair<int, int> s,e;
    vector<pair<int, int> > req;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]=='S') s={i, j};
            else if(table[i][j]=='E') e={i, j};
            else if(table[i][j]=='X') req.push_back({i, j});
    
    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(1<<req.size(), INT32_MAX/2)));
    queue<tuple<int, int, int> > q;
    q.push({s.first, s.second, 0});
    dist[s.first][s.second][0]=0;

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x, y, mask]=q.front();
        q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=way[w][0]+x, ny=way[w][1]+y;
            if(!(0<=nx and nx<n and 0<=ny and ny<m)) continue;
            int next_mask=mask;
            if(table[nx][ny]=='X')
            {
                int target_idx=find(req.begin(), req.end(), make_pair(nx, ny))-req.begin();
                next_mask|=(1<<target_idx);
            }
            if(table[nx][ny]!='#')
            {
                if(dist[nx][ny][next_mask] > dist[x][y][mask]+1)
                    q.push({nx, ny, next_mask}), dist[nx][ny][next_mask]=dist[x][y][mask]+1;
            } 
        }
    }

    printf("%d", dist[e.first][e.second][(1<<req.size())-1]);
}

/*
    
*/