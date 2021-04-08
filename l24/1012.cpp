// https://www.acmicpc.net/problem/1012
// 2021-04-08 21:44:26 0ms
#include<iostream>
using namespace std;

const int way[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int **arr, *visited;


void dfs(int x, int y, int x_limit, int y_limit)
{
    visited[x*y_limit+y]=1;

    for(int i=0; i<4; i++)
    {
        int dx=x+way[i][0], dy=y+way[i][1];
        if(dx>=0 && dx<x_limit && dy>=0 && dy<y_limit)
            if(arr[dx][dy]==1 && visited[dx*y_limit+dy]==0)
                dfs(dx, dy, x_limit, y_limit);
    }

}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int m,n,k; scanf("%d%d%d", &m,&n,&k);

        arr=new int*[m];
        for(int i=0; i<m; i++)
            arr[i]=new int[n];
        visited=new int[m*n];
        // 2차원 배열 동적할당

        for(int i=0; i<k; i++)
        {
            int x,y; scanf("%d%d", &x,&y);
            arr[x][y]=1;
        }

        int count=0;
        for(int i=0; i<n*m; i++)
            if(visited[i]==0 && arr[i/n][i%n]==1)
            {
                count++;
                dfs(i/n, i%n, m,n);
            }
        printf("%d\n", count);
    }
}