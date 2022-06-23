// https://www.acmicpc.net/problem/16920
// 2022-06-23 22:17:31 1780ms
#include"bits/stdc++.h"
using namespace std;

struct status
{
    int x,y,cnt;
};

int main(void)
{
    int n,m,p; scanf("%d%d%d", &n, &m, &p);
    
    vector<vector<int> > table(n, vector<int>(m));
    vector<queue<pair<int,int> > > next_castle(p+1);
    vector<int> move_cnt(p+1), castle_cnt(p+1);

    for(int i=0; i<p; i++)
        scanf("%d", &move_cnt[i+1]);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            char c; scanf(" %c", &c);
            if(c == '#') table[i][j]=-1;
            else if(isdigit(c))
                table[i][j]=c-'0', next_castle[c-'0'].push({i, j}), castle_cnt[c-'0']++;
        }

    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(true)
    {
        int expend_cnt=0;
        // 후보별로 확장을 시도해보기
        for(int i=1; i<p+1; i++)
        {
            // 움직일 수 있는 자리가 한 칸이라도 있다면, Si에서 반복해서 2를 뺄 수 있음
            queue<status> q;
            while(next_castle[i].size())
            {
                q.push({next_castle[i].front().first, next_castle[i].front().second, 0});
                next_castle[i].pop();
            }

            vector<vector<int> > visited(n, vector<int>(m));
            while(q.size())
            {
                status now=q.front(); q.pop();
                if(now.cnt > move_cnt[i] or visited[now.x][now.y]) continue;

                if(table[now.x][now.y] != i) 
                    if(!visited[now.x][now.y])
                    {
                        table[now.x][now.y]=i;
                        expend_cnt++, castle_cnt[i]++;
                        next_castle[i].push({now.x, now.y});
                    }
                visited[now.x][now.y]=1;

                for(int w=0; w<4; w++)
                {
                    int nx=now.x+way[w][0], ny=now.y+way[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m)
                        if((table[nx][ny] == i or !table[nx][ny]) and !visited[nx][ny]) // 자기 성은 또 지나다닐수가 있다네?
                            q.push({nx, ny, now.cnt+1});
                }
            }
        //     printf("--\n");
        //     for(int i=0; i<n; i++)
        //     {
        //         for(int j=0; j<m; j++)
        //             printf("%d ", table[i][j]);
        //         printf("\n");
        //     }
        }

        if(!expend_cnt) break;
    }
    
    for(int i=1; i<p+1; i++)
        printf("%d ", castle_cnt[i]);
}

/*
    
*/