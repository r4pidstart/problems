// https://www.acmicpc.net/problem/22116
// 2024-01-20 01:26:17
#include"bits/stdc++.h"
using namespace std;

int decision(int mid, const vector<vector<int> >& table)
{
    const int n=table.size();
    queue<pair<int,int> > q;
    vector<vector<int> > visited(n, vector<int>(n));
    q.push({0, 0});

    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x,y]=q.front();
        q.pop();

        if(x==n-1 and y==n-1)
            return 1;
        
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<n and abs(table[x][y]-table[nx][ny])<=mid and !visited[nx][ny])
                q.push({nx, ny}), visited[nx][ny]=1;
        }
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    int lo=0, hi=1e9, ans=1e9;
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);

    while(lo<=hi)
    {
        int mid=(1L*lo+hi)/2;
        if(decision(mid, table))
            hi=mid-1, ans=mid;
        else
            lo=mid+1;
    }
    printf("%d", ans);
}

/*
    
*/