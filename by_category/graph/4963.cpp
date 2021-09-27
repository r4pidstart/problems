// https://www.acmicpc.net/problem/4963 
// 2021-09-28 03:16:48 0ms
#include<bits/stdc++.h>
using namespace std;

int cnt;
const int way[8][2]={{0,1}, {1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}, {-1,0}, {0,-1}};
vector<vector<int> > field, visited;

void dfs(int x, int y)
{
    if(visited[x][y]) return;
    visited[x][y]=cnt;

    for(int i=0; i<8; i++)
    {
        int nx=x+way[i][0], ny=y+way[i][1];
        if(!(0<=nx && nx<field.size() && 0<=ny && ny<field[0].size())) continue;
        if(!field[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main(void)
{
    while(true)
    {
        cnt=1;
        int w,h; scanf("%d%d", &h, &w);

        if(w==0 && h==0) break;

        field.assign(w, vector<int>(h,0));
        visited.assign(w, vector<int>(h,0));

        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
                scanf("%d", &field[i][j]);
        
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
                if(field[i][j] && !visited[i][j]) 
                {
                    dfs(i,j); 
                    cnt++;
                }
        
        printf("%d\n", cnt-1);
    }

    
}

/*
    
*/