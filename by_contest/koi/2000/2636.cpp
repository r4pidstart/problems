// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n+2, vector<int>(m+2));
    int prev_cnt=0, cnt=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &table[i][j]);
            if(table[i][j]) prev_cnt++;
        }
    
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(true)
    {
        cnt++;
        // bfs
        int del_cnt=0;
        vector<vector<int> > visited(n+2, vector<int>(m+2));
        queue<pair<int,int> > q;
        q.push({0,0});
        while(q.size())
        {
            auto [x,y]=q.front(); q.pop();
            if(visited[x][y]) continue;
            visited[x][y]=1;
            if(table[x][y])
            {
                del_cnt++;
                table[x][y]=0;
                continue;
            }

            for(int w=0; w<4; w++)         
            {
                int nx=x+way[w][0], ny=y+way[w][1];
                if(0<=ny and nx<=n and 0<=nx and ny<=m)
                    q.push({nx, ny});
            }   
        }

        if(prev_cnt == del_cnt)
            return !printf("%d\n%d", cnt, del_cnt);
        prev_cnt -= del_cnt;
    }
}

/*
    
*/