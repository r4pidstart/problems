// https://www.acmicpc.net/problem/24513
// 2023-09-21 22:05:07
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));

    queue<tuple<int,int,int> > q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf("%d", &table[i][j]);
            if(table[i][j]==1 or table[i][j]==2)
                q.push({i, j, table[i][j]});
        }

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    vector<vector<int> > visited(n, vector<int>(m));
    int visit_time=0;
    while(q.size())
    {
        int q_size=q.size();
        visit_time++;
        while(q_size--)
        {
            auto [x, y, t]=q.front();
            q.pop();

            if(table[x][y]==3)
                continue;

            for(int i=0; i<4; i++)
            {
                int nx=x+way[i][0], ny=y+way[i][1];
                if(0<=nx and nx<n and 0<=ny and ny<m)
                {
                    // first visit
                    if(table[nx][ny]==0)
                    {
                        q.push({nx, ny, t});
                        table[nx][ny]=t;
                        visited[nx][ny]=visit_time;
                    }
                    else if(((t==2 and table[nx][ny]==1) or (t==1 and table[nx][ny]==2)) and visited[nx][ny]==visit_time)
                    {
                        table[nx][ny]=3;
                    }
                }
            }
        }       
    }

    vector<int> arr(3);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(table[i][j]>0)
                arr[table[i][j]-1]++;
    
    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/