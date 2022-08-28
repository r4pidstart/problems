// https://www.acmicpc.net/problem/4179
// 2022-08-28 23:15:16 76ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int r,c; scanf("%d%d", &r, &c);
    vector<vector<char> > table(r, vector<char>(c)), visited(r, vector<char>(c));
    queue<pair<int, pair<int,int> > > q2;
    queue<pair<int,int> > q1;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j]=='F')
                q1.push({i, j});
            else if(table[i][j]=='J')
                q2.push({0, {i, j}}), visited[i][j]=1;
        }
    
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(q1.size() or q2.size())
    {
        int me_count=q2.size();
        while(me_count--)
        {
            auto me=q2.front(); q2.pop();
            if(table[me.second.first][me.second.second] == 'F') continue;
            for(int w=0; w<4; w++)
            {
                int nx=me.second.first+way[w][0], ny=me.second.second+way[w][1];
                if(0<=nx and nx<r and 0<=ny and ny<c)
                {
                    if(visited[nx][ny] or table[nx][ny] == '#' or table[nx][ny] == 'F') continue;
                    visited[nx][ny]=1, q2.push({me.first+1, {nx, ny}});
                }
                else
                    return !printf("%d", me.first+1);
            }
        }

        int fire_cnt=q1.size();
        while(fire_cnt--)
        {
            int x=q1.front().first, y=q1.front().second; q1.pop();
            for(int w=0; w<4; w++)
            {
                int nx=x+way[w][0], ny=y+way[w][1];
                if(0<=nx and nx<r and 0<=ny and ny<c and table[nx][ny] != 'F' and table[nx][ny] != '#')
                    table[nx][ny]='F', q1.push({nx, ny});
            }
        }
        // printf("\n");
        // for(int i=0; i<r; i++)
        // {
        //     for(int j=0; j<c; j++)
        //         printf("%d ", visited[i][j]);
        //     printf("\n");
        // }
        // printf("\n");
        // for(int i=0; i<r; i++)
        // {
        //     for(int j=0; j<c; j++)
        //         printf("%c", table[i][j]);
        //     printf("\n");
        // }
    }
    printf("IMPOSSIBLE");
}

/*
    
*/