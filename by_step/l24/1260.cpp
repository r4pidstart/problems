// https://www.acmicpc.net/problem/1260
// 2021-04-08 00:55:07 8ms
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int point[1001]={};
int arr[1001][1001]={};

void dfs(int start, int n)
{
    printf("%d ", start);
    point[start]=true;
    for(int i=1; i<=n; i++)
    {
        if(point[i]!=true && arr[start][i]==1)
            dfs(i,n);
    }
}

void bfs(int start, int n)
{
    queue<int> bfs;
    bfs.push(start);
    point[start]=1;
    while(!bfs.empty())
    {
        int now=bfs.front();
        bfs.pop();
        printf("%d ", now);
        for(int i=1; i<=n; i++)
            if(point[i]!=true && arr[now][i]==1)
            {
                bfs.push(i);
                point[i]=1;
            }
    }
}

int main(void)
{
    int n,m,start; scanf("%d%d%d", &n, &m, &start);
    
    for(int i=0; i<m; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        arr[x][y] = arr[y][x] = 1;
    }
    
    dfs(start,n);
    memset(point, 0, sizeof(int)*1001);
    printf("\n");
    bfs(start,n);
}