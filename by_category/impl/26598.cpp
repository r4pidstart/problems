// https://www.acmicpc.net/problem/26598
// 2022-12-27 00:51:02
#include"bits/stdc++.h"
using namespace std;

vector<int> cnt;
void dfs(int x, int y, int idx, vector<vector<char> >& table, vector<vector<int> >& visited)
{
    visited[x][y]=idx;
    if(cnt.size() <= idx)
        cnt.push_back(1);
    else
        cnt[idx]++;
    
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for(int w=0; w<4; w++)
    {
        int nx=x+way[w][0], ny=y+way[w][1];
        if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size() and visited[nx][ny]==-1 and table[x][y] == table[nx][ny])
            dfs(nx, ny, idx, table, visited);
    }
}

int check(int i, int j, int idx, vector<vector<char> >& table)
{
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    int x=i, y=j;
    int wmax=i, hmax=j; 
    for(int w=0; w<4; w++)
    {
        while(true)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size() and table[x][y] == table[nx][ny])
                x=nx, y=ny;
            else 
                break;
            wmax=max(wmax, x), hmax=max(hmax, y);
        }
    }
    if((wmax-i+1) * (hmax-j+1) == cnt[idx] and i==x and j==y)
        return 0;
    else 
        return 1;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<char> > table(n, vector<char>(m));
    vector<vector<int> > visited(n, vector<int>(m, -1));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    int idx=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(visited[i][j] == -1)
                dfs(i, j, idx++, table, visited);
    
    // rectangle check
    idx=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(idx == visited[i][j])
                if(check(i, j, idx++, table))
                    return !printf("BaboBabo");
    printf("dd");
}

/*
    
*/