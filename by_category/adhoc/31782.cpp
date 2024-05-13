// https://www.acmicpc.net/problem/31782
// 2024-05-11 17:54:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m,k; cin >> n >> m >> k;
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> table[i][j];
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    {
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(table[i][j]=='O')
                    q.push({i, j});
        
        while(q.size())
        {
            auto [x, y]=q.front();
            q.pop();

            for(int w=0; w<4; w++)
            {
                int nx=x+way[w][0], ny=y+way[w][1];
                if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='.')
                {
                    int cnt=0;
                    for(int ww=0; ww<4; ww++)
                    {
                        int nnx=nx+way[ww][0], nny=ny+way[ww][1];
                        if(0<=nnx and nnx<n and 0<=nny and nny<m and table[nnx][nny]=='O')
                            cnt++;
                    }
                    if(cnt>=2)
                        q.push({nx, ny}), table[nx][ny]='O';
                }
            }
        }
    }

#ifdef LOCAL
    printf("\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%c ", table[i][j]);
        printf("\n");
    }
#endif

    vector<pair<int,int> > rec;
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(table[i][j]=='O' and !visited[i][j])
            {
                queue<pair<int, int> > q;
                q.push({i, j});
                visited[i][j]=1;

                int minx=i, maxx=i, miny=j, maxy=j; 
                while(q.size())
                {
                    auto [x, y]=q.front();
                    q.pop();

                    minx=min(x, minx), maxx=max(x, maxx);
                    miny=min(y, miny), maxy=max(y, maxy);

                    for(int w=0; w<4; w++)
                    {
                        int nx=x+way[w][0], ny=y+way[w][1];
                        if(0<=nx and nx<n and 0<=ny and ny<m and table[nx][ny]=='O' and !visited[nx][ny])
                        {
                            q.push({nx, ny});
                            visited[nx][ny]=1;
                        }
                    }
                }
                rec.push_back({maxx-minx+1, maxy-miny+1});
            }
        }
    
    int ans=0;
    for(auto [w, h] : rec)
        if(w>k and h>k)
            ans+=w*h;
    cout << ans;
}

/*
    
*/