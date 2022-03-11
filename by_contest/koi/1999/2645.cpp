// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    int sx, sy, ex, ey; scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    int k; scanf("%d", &k);

    vector<vector<int> > table(n+1, vector<int>(n+1,0));

    // draw circuit
    int circuit_num; scanf("%d", &circuit_num);
    while(circuit_num--)
    {
        int n; scanf("%d", &n);
        int prev_x, prev_y; scanf("%d%d", &prev_x, &prev_y);
        while(--n)
        {
            int nowx, nowy; scanf("%d%d", &nowx, &nowy);
            for(int i=min(prev_x, nowx); i<=max(prev_x, nowx); i++)
                for(int j=min(prev_y, nowy); j<=max(prev_y, nowy); j++)
                    table[i][j]=1;
            prev_x=nowx, prev_y=nowy;
        }
    }

    // dijkstra
    queue<pair<int,int> > q;
    vector<vector<int> > dist(n+1, vector<int>(n+1, INT32_MAX/2));
    vector<vector<pair<int,int> > > prev(n+1, vector<pair<int,int> >(n+1, {-1, -1})); 
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    q.push({ex, ey});
    dist[ex][ey]=0;
    while(!q.empty())
    {
        auto [x,y]=q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=x+mov[i][0], ny=y+mov[i][1];
            if(0<nx and nx<=n and 0<ny and ny<=n)
            {
                int next_dist=dist[x][y]+(table[nx][ny] ? k:1);
                if(next_dist < dist[nx][ny])
                    q.push({nx, ny}), dist[nx][ny]=next_dist, prev[nx][ny]={x, y};
            }
        }
    }

    pair<int,int> cur={sx, sy};
    int dir=0;
    vector<pair <int,int>> ans;
    while(cur != make_pair(-1, -1))
    {
        if(cur.first == prev[cur.first][cur.second].first) // dir 1
        {
            if(dir != 1)
                ans.push_back({cur.first, cur.second});
            dir=1;
        }
        else // dir 2
        {
            if(dir != 2)
                ans.push_back({cur.first, cur.second});
            dir=2;
        }
        cur=prev[cur.first][cur.second];
    }

    if(ans.back() != make_pair(ex, ey))
        ans.push_back({ex, ey});
    printf("%d\n%d ", dist[sx][sy]+1, ans.size());
    for(auto it : ans)
        printf("%d %d ", it.first, it.second);
}

/*
    
*/