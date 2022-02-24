// https://www.acmicpc.net/problem/16197
// 2022-02-24 22:45:32 56ms
#include<bits/stdc++.h>
using namespace std;

int n,m,ans=11;
vector<vector<char> > table;

void dfs(int x1, int y1, int x2, int y2, int cnt)
{
    const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    if(cnt > 10)
        return;
    if(((x1<0 || n<=x1) || (y1<0 || m<=y1)) && ((x2<0 || n<=x2) || (y2<0 || m<=y2)))
        return;
    if(((x1<0 || n<=x1) || (y1<0 || m<=y1)) && (0<=x2 && x2<n && 0<=y2 && y2<m))
    {
        ans = min(ans, cnt);
        return;
    }
    if(((x2<0 || n<=x2) || (y2<0 || m<=y2)) && (0<=x1 && x1<n && 0<=y1 && y1<m))
    {
        ans = min(ans, cnt);
        return;
    }
    for(int i=0; i<4; i++)
    {
        int nx1=x1+mov[i][0], ny1=y1+mov[i][1], nx2=x2+mov[i][0], ny2=y2+mov[i][1];
        if(0<=nx1 && nx1<n && 0<=ny1 && ny1<m && table[nx1][ny1]=='#')
            nx1-=mov[i][0], ny1-=mov[i][1];
        if(0<=nx2 && nx2<n && 0<=ny2 && ny2<m && table[nx2][ny2]=='#')
            nx2-=mov[i][0], ny2-=mov[i][1];
        if(!(nx1==x1 and nx2==x2 and ny1==y1 and ny2==y2))
            dfs(nx1, ny1, nx2, ny2, cnt+1);
    }
}

int main(void)
{
    scanf("%d%d", &n,&m);
    table.assign(n, vector<char>(m));
    int x1=-1,y1,x2,y2;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            scanf(" %c", &table[i][j]);
            if(table[i][j] == 'o')
            {
                if(x1 == -1) x1=i, y1=j;
                else x2=i, y2=j;
            }
        }
    dfs(x1, y1, x2, y2, 0);
    printf("%d", ans<=10 ? ans:-1);
}

/*
    
*/