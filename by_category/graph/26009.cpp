// https://www.acmicpc.net/problem/26009
// 2022-11-27 15:10:41
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<vector<int> > visited(n, vector<int>(m));
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    for(int i=0; i<k; i++)
    {
        int a,b,d; scanf("%d%d%d", &a, &b, &d);
        a--, b--;

        int x=a-d, y=b;
        visited[a][b]=-2;
        while(y != b+d)
        {
            if(0<=x and x<n and 0<=y and y<m)
                visited[x][y]=-1;
            x++, y++;
        }
        while(x != a+d)
        {
            if(0<=x and x<n and 0<=y and y<m)
                visited[x][y]=-1;
            x++, y--;
        }
        while(y != b-d)
        {
            if(0<=x and x<n and 0<=y and y<m)
                visited[x][y]=-1;
            x--, y--;
        }
        while(x != a-d)
        {
            if(0<=x and x<n and 0<=y and y<m)
                visited[x][y]=-1;
            x--, y++;
        }
    }

    // printf("\n");
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //         printf("%d ", visited[i][j]);
    //     printf("\n");
    // }
    queue<pair<int,int> > q;
    q.push({0,0});
    visited[0][0]=1;
    while(q.size())
    {
        auto [x, y]=q.front();
        q.pop();

        if(x == n-1 and y == m-1)
            return !printf("YES\n%d", visited[x][y]-1);
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny])
            {
                visited[nx][ny]=visited[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    printf("NO");
}

/*
    
*/