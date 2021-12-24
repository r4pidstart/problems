// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;

struct status
{
    int time, x, y, mask;
};

struct comp
{
    bool operator()(const status& a, const status& b)
    {
        return a.time>b.time;
    }
};

inline int calc(int dir,int now)
{
    if(dir>=now) return dir-now; 
    else return dir+4-now;
}

int main(void)
{
    cin.tie(NULL)->sync_with_stdio(false);
    // N -> E -> S -> W, 0 -> 1 -> 2 -> 3
    const int way[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};
    while(true)
    {
        int m,n; cin >> m >> n;
        if(m==0 and n==0) break;

        vector<vector<int> > table(m, vector<int>(n));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                char c; cin >> c;
                if(c=='N') table[i][j]=0;
                else if(c=='E') table[i][j]=1;
                else if(c=='S') table[i][j]=2;
                else if(c=='W') table[i][j]=3;
            }

        vector<vector<int> > t_box(m, vector<int>(n));
        int k; cin >> k;
        for(int i=0; i<k; i++)
        {
            int a,b; cin >> a >> b;
            t_box[a-1][b-1]=i+1;
        }

        priority_queue<status, vector<status>, comp>  q;
        vector<vector<vector<int> > > visited(m, vector<vector<int> >(n, vector<int>((1<<(k+1))-1, INT32_MAX)));
        visited[0][0][0]=0;
        q.push(status({0,0,0,0}));

        status now;
        while(!q.empty())
        {
            now=q.top(); q.pop();
            if(now.mask == (1<<k)-1 and now.x == m-1 and now.y == n-1) break;
            if(now.time > visited[now.x][now.y][now.mask]) continue;

            for(int i=0; i<4; i++)
            {
                int nx=now.x+way[i][0], ny=now.y+way[i][1];
                if(!(0<=nx and nx<m and 0<=ny and ny<n)) continue;
                int next_time=visited[now.x][now.y][now.mask]+calc(i, (table[now.x][now.y]+visited[now.x][now.y][now.mask])%4)+1;
                if(t_box[nx][ny])
                {
                    int next_mask=now.mask|(1<<(t_box[nx][ny]-1));
                    if(visited[nx][ny][next_mask] > next_time)
                    {
                        q.push({next_time, nx, ny, next_mask});
                        visited[nx][ny][next_mask]=next_time;
                    }
                }
                else
                {
                    if(visited[nx][ny][now.mask] > next_time)
                    {
                        q.push({next_time, nx, ny, now.mask});
                        visited[nx][ny][now.mask]=next_time;
                    }
                }
            }
        }
        cout << now.time << '\n';
    }
}

/*
    
*/