
#include<bits/stdc++.h>
using namespace std;

struct argu
{
    int x,y, mask, cnt;
};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    const int way[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<char> > maze(n+1, vector<char>(m+1));
    vector<vector<vector<int> > > visited(n+1, vector<vector<int>>(m+1, vector<int>(1<<6,0)));
    pair<int,int> start;
    getchar();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%c", &maze[i][j]);
            if(maze[i][j]=='0')
                start={i,j};
        }
        getchar();
    }

    // bitmask bfs
    stack<argu> bfs;
    bfs.push({start.first, start.second, 0, 0});
    visited[start.first][start.second][0]=1;
    while(!bfs.empty())
    {
        argu now=bfs.top();
        bfs.pop();
        for(int i = 0; i < 4; i++) {
        int tx = now.x + way[i][0];
        int ty = now.y + way[i][1];
        int tKey = now.mask;

        // 미로 범위 안
        if(tx < 1 || tx > n || ty < 1 || ty > m)  continue;

        // 탈출한 경우
        if(maze[now.x][now.y] == '1')
        {
            printf("%d", now.cnt);
            return 0;
        }

        // 벽인 경우
        if(maze[tx][ty] == '#') continue;

        // 문이면서 키가 없는 경우
        if('A' <= maze[tx][ty] && maze[tx][ty] <= 'F') {
                if((tKey & (1 << (maze[tx][ty] - 'A'))) == 0) continue;
        }

        // 키인 경우
        if('a' <= maze[tx][ty] && maze[tx][ty] <= 'f') {
                tKey = tKey | (1 << (maze[tx][ty] - 'a'));
        }

        // 이미 동일한 키 목록으로 방문한 경우
        if(visited[tx][ty][tKey]) continue;

        // 방문 처리
        visited[tx][ty][tKey] = true;
        bfs.push({tx, ty, tKey, now.cnt + 1});
        }
    }
    printf("-1");
}