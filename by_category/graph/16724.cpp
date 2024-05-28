// https://www.acmicpc.net/problem/16724
// 2024-05-27 23:06:57
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int check(int x, int y, const vector<vector<char> >& table, int start=0)
{
    static int cnt=0;
    static vector<vector<int> > visited(table.size(), vector<int>(table[0].size()));

    if(start) cnt++;

    if(visited[x][y])
        return visited[x][y]==cnt;

    visited[x][y]=cnt;

    switch(table[x][y])
    {
        case 'U':
            return check(x-1, y, table);
        case 'D':
            return check(x+1, y, table);
        case 'L':
            return check(x, y-1, table);
        case 'R':
            return check(x, y+1, table);
    }
    return 0;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,m; cin >> n >> m;
    vector<vector<char> > table(n, vector<char>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> table[i][j];

    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans+=check(i, j, table, 1);
    cout << ans;
}

/*
    
*/