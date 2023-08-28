// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int k; scanf("%d", &k);
    int n,m; scanf("%d%d", &n, &m);
    swap(n, m);
    vector<vector<int> > table(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &table[i][j]);
    
    vector<vector<vector<int> > > dist(n, vector<vector<int> >(m, vector<int>(k+1, -1)));
    dist[0][0][0]=0;
    queue<tuple<int,int,int,int> > q;
    q.push({0,0,0,0});
    
    const int hway[8][2]={{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x,y,h,cnt]=q.front();
        q.pop();

        if(x==n-1 and y==m-1)
            return !printf("%d", cnt);
        if(k != h)
        {
            for(int w=0; w<8; w++)
            {
                int nx=x+hway[w][0], ny=y+hway[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<m and !table[nx][ny] and dist[nx][ny][h+1]==-1)
                    dist[nx][ny][h+1]=cnt+1, q.push({nx, ny, h+1, cnt+1});
            }
        }

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and !table[nx][ny] and dist[nx][ny][h]==-1)
                dist[nx][ny][h]=cnt+1, q.push({nx, ny, h, cnt+1});
        }
    }
    printf("-1");
}

/*
    
*/