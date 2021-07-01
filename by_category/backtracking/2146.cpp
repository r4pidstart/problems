// https://www.acmicpc.net/problem/2146
// 2021-07-02 00:42:46 52ms
#include<bits/stdc++.h>
using namespace std;

const int w[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n; 
vector<vector<int> > m, is_idx;

int get_is_idx(int x, int y)
{
    static int idx=0;
    idx++;

    queue<pair<int,int> > q;
    q.push({x,y});
    is_idx[x][y]=idx;
    while(!q.empty())
    {
        for(int i=0; i<4; i++)
        {
            int nx=q.front().first+w[i][0], ny=q.front().second+w[i][1];
            if(nx>=0 && nx<n && ny>=0 && ny<n && m[nx][ny] && !is_idx[nx][ny])
            {
                is_idx[nx][ny]=idx;
                q.push({nx,ny});
            }
        }
        q.pop();
    }
    return 0;
}

int get_shortest_bridge(int x, int y)
{
    vector<vector<int> > visited(n, vector<int>(n,0));
    int now=is_idx[x][y];
    queue<pair<int, pair<int,int> > > q;
    q.push({0 ,{x,y}});
    while(!q.empty())
    {
        for(int i=0; i<4; i++)
        {
            int nx=q.front().second.first+w[i][0], ny=q.front().second.second+w[i][1];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny] && (now!=is_idx[nx][ny]))
            {
                if(m[nx][ny]!=0)
                    return q.front().first;
                q.push({q.front().first+1, {nx,ny}});
                visited[nx][ny]++;
            }
        }
        q.pop();
    }
    return INT32_MAX;
}


int main(void)
{
    scanf("%d", &n);
    m=is_idx=vector<vector<int> >(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &m[i][j]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(m[i][j] && !is_idx[i][j])
                get_is_idx(i,j);

    int ans=INT32_MAX;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(is_idx[i][j])
                ans=min(ans, get_shortest_bridge(i,j));

    printf("%d", ans);
}

/*

*/