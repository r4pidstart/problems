// https://www.acmicpc.net/problem/2583
// 2022-03-17 00:06:31 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int m,n,k; scanf("%d%d%d", &m, &n, &k);
    vector<vector<int> > table(n, vector<int>(m, 1));

    for(int i=0; i<k; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a,&b,&c,&d);
        c--, d--;
        for(int i=a; i<=c; i++)
            for(int j=b; j<=d; j++)
                table[i][j]=0;
    }

    // bfs
    const int mov[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    vector<int> area;
    vector<vector<int> > visited(n, vector<int>(m));
    queue<pair<int,int> > q;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(!table[i][j] or visited[i][j]) continue;
            
            q.push({i,j});

            int tmp=0;
            while(!q.empty())
            {
                auto [x,y]=q.front(); q.pop();
                if(visited[x][y]) continue;
                visited[x][y]=1;

                tmp++;
                for(int w=0; w<4; w++)
                {
                    int nx=x+mov[w][0], ny=y+mov[w][1];
                    if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny])
                        q.push({nx, ny});
                }
            }
            area.push_back(tmp);
        }

    printf("%d\n", area.size());
    sort(area.begin(), area.end());
    for(auto i : area)
        printf("%d ", i);
}

/*
    
*/