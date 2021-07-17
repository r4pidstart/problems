// https://www.acmicpc.net/problem/1103
// 2021-07-17 23:44:10 0ms
#include<bits/stdc++.h>
using namespace std;

int n,m;
const int w[4][2]={{0,1}, {1, 0}, {-1, 0}, {0, -1}};
vector<vector<int> > field, visited, memo, checked;

int dfs(int x, int y)
{
    if(field[x][y]=='H')
        return memo[x][y]=0;
    if(visited[x][y])
    {
        printf("-1");
        exit(0);
    }
    if(checked[x][y])
        return memo[x][y];

    checked[x][y]=visited[x][y]=1;
    int ret=0;
    
    for(int i=0; i<4; i++)
    {
        int nx=x+w[i][0]*(field[x][y]-'0'), ny=y+w[i][1]*(field[x][y]-'0');
        if(!(0<=nx && nx<n && 0<=ny && ny<m)) continue;
        ret=max(ret, dfs(nx,ny));
        visited[nx][ny]=0;
    }
    return memo[x][y]=ret+1;
}

int main(void)
{
    scanf("%d%d", &n,&m);
    memo=vector<vector<int> >(n, vector<int>(m,-1));
    checked=field=visited=vector<vector<int> >(n, vector<int>(m,0));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("\n %c", &field[i][j]);

    printf("%d", dfs(0,0));
}

/*

*/
