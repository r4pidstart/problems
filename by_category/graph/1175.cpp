// https://www.acmicpc.net/problem/1175 
// 2023-03-11 13:01:20
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > arr(n, vector<int>(m));
    pair<int, int> start, target1(-1, -1), target2;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &arr[i][j]);
            if(arr[i][j]=='S') start={i,j};
            if(arr[i][j]=='C')
            {
                if(target1.first==-1) target1={i,j};
                else target2={i,j};
            }
        }
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    vector<vector<vector<vector<int> > > > visited
        (n, vector<vector<vector<int> > >(m, vector<vector<int> >(4, vector<int>(4))));
    // x, y, prev_dir, delivered, dist
    queue<tuple<int, int, int, int, int> > q;
    q.push({start.first, start.second, -1, 0, 0});
    while(q.size())
    {
        auto [x, y, prev_dir, delivered, dist]=q.front();
        q.pop();
        if(delivered==3)
            return !printf("%d", dist);
        
        for(int i=0; i<4; i++)
        {
            if(prev_dir==i) continue;
            int nx=x+way[i][0], ny=y+way[i][1];
            int next_status=delivered | (make_pair(nx, ny)==target1) << 1 | (make_pair(nx, ny)==target2) << 0;
            if(0<=nx and nx<n and 0<=ny and ny<m and arr[nx][ny]!='#' and !visited[nx][ny][i][next_status])
                visited[nx][ny][i][next_status]=1, q.push({nx, ny, i, next_status, dist+1});
        }
    }
    printf("-1");
}

/*
    
*/