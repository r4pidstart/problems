// https://www.acmicpc.net/problem/21736
// 2023-11-04 01:02:34
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > table(n, vector<int>(m));

    queue<pair<int,int> > q;
    vector<vector<int> > visited(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j]=='I') q.push({i, j}), visited[i][j]=1;
        }
    
    int cnt=0;
    const int way[8][2]={{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(q.size())
    {
        auto [x,y]=q.front(); q.pop();

        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(0<=nx and nx<n and 0<=ny and ny<m and !visited[nx][ny] and table[nx][ny]!='X')
                q.push({nx, ny}), visited[nx][ny]=1, cnt+=table[nx][ny]=='P';
        }
    }
    if(cnt==0)
        printf("TT");
    else
        printf("%d", cnt);
}

/*
    
*/