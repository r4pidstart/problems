// https://www.acmicpc.net/problem/1025
// 2023-07-19 05:12:53
#include"bits/stdc++.h"
using namespace std;

int dfs(int x, int y, int dx, int dy, int now, vector<vector<int> >& table)
{
    static int max_val=-1;
    int tmp=sqrt(now);
    if(tmp*tmp==now)
        max_val=max(max_val, now);
    
    int nx=x+dx, ny=y+dy;
    if(0<=nx and nx<table.size() and 0<=ny and ny<table[0].size())
        dfs(nx, ny, dx, dy, now*10+table[nx][ny], table);

    return max_val;
}

int get_max(vector<vector<int> >& table)
{
    int ret=-1;
    for(int i=0; i<table.size(); i++)
        for(int j=0; j<table[0].size(); j++)
            for(int dx=-9; dx<10; dx++)
                for(int dy=-9; dy<10; dy++)
                    if(dx or dy)
                        ret=max(ret, dfs(i, j, dx, dy, table[i][j], table));
    return ret;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &table[i][j]);
    
    printf("%d", get_max(table));

}

/*
    
*/