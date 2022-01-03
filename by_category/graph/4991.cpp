// https://www.acmicpc.net/problem/4991
// 2022-01-04 02:36:44 60ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    while(true)
    {
        int w,h; scanf("%d%d", &w, &h);
        if(w==0 and h==0) break;
        vector<vector<char> > table(h, vector<char>(w));
        pair<int,int> start;
        vector<pair<int,int> > dust;
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                scanf(" %c", &table[i][j]);
                if(table[i][j] == 'o') start={i,j};
                if(table[i][j] == '*') dust.push_back({j,i});
            }
        
        struct s{int x, y, mask, cnt;};
        const int way[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<vector<int> > > visited(h, vector<vector<int> >(w, vector<int>( 1<<dust.size() )));
        queue<s> q;
        q.push({start.first, start.second, 0, 0});
        
        s now;
        while(!q.empty())
        {
            now=q.front(); q.pop();
            if(now.mask == (1<<dust.size())-1) break;
            if(visited[now.x][now.y][now.mask]) continue;
            visited[now.x][now.y][now.mask]=1;

            for(int i=0; i<4; i++)
            {
                int nx=now.x+way[i][0], ny=now.y+way[i][1];
                if(0<=nx and nx<h and 0<=ny and ny<w)
                {
                    if(table[nx][ny] == '*')
                    {
                        int nextMask;
                        for(int j=0; j<dust.size(); j++)
                            if(dust[j] == make_pair(ny,nx))
                                nextMask = now.mask | (1<<j);
                        q.push({nx, ny, nextMask, now.cnt+1});
                    }
                    else if(table[nx][ny] != 'x')
                    {
                        q.push({nx, ny, now.mask, now.cnt+1});
                    }
                }
            }
        }

        if(now.mask == (1<<dust.size())-1) printf("%d\n", now.cnt);
        else printf("-1\n");
    }
}

/*

*/