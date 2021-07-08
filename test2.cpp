// https://www.acmicpc.net/problem/
// 
#include<bits/stdc++.h>
using namespace std;

int n, ans=0;
vector<vector<int> > table;
// 0:놓을 수 없는 곳, 1:놓을 수 있는 곳 

void print_map(void)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }
    printf("\n");
}

void toggle_bishop(int x, int y, int cnt)
{
    const int move[4][2]={{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

    if(table[x][y]==1) table[x][y]=cnt;
    else if(table[x][y]==cnt) table[x][y]=1;

    for(int i=0; i<4; i++)
    {
        int nx=x+move[i][0], ny=y+move[i][1];
        while(0<=nx && n>nx && 0<=ny && n>ny)
        {
            if(table[nx][ny]==1) table[nx][ny]=cnt;
            else if(table[nx][ny]==cnt) table[nx][ny]=1;
            nx+=move[i][0], ny+=move[i][1];
        }
    }
    // print_map();
}

void dfs(int x, int y, int cnt)
{
    for(int i=x; i<n; i++)
    {
        if(table[i][y]==1)
        {
            toggle_bishop(i, y, cnt);
            dfs(i, y, cnt+1);
            ans=max(ans, cnt+1);
            toggle_bishop(i, y, cnt);
        }
    }

    for(int j=y+1; j<n; j++)
        for(int i=0; i<n; i++)
        {
            if(table[i][j]==1)
            {
                toggle_bishop(i, j, cnt);
                dfs(i, j, cnt+1);
                ans=max(ans, cnt+1);
                toggle_bishop(i, j, cnt);
            }
        }
}

int main(void)
{
    scanf("%d", &n);
    table.assign(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
        
    dfs(0,0,2);
    printf("%d", ans-2);
}

/*

*/