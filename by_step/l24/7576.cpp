// https://www.acmicpc.net/problem/7576
// 2021-04-10 20:43:06 128ms
#include<iostream>
#include<queue>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))

const int way[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void)
{
    int m,n; scanf("%d%d", &m,&n);
    int arr[n][m]={};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);

    queue<pair<int,int>> bfs;
    int count=0;
    for(int i=0; i<m*n; i++)
        if(arr[i/m][i%m]==1)
        {
            bfs.push({i/m,i%m});
            count++;
        }
    
    if(count==0)
    {
        printf("-1");
        return 0;
    }

    while(!bfs.empty())
    {
        int x=bfs.front().first, y=bfs.front().second;
        bfs.pop();
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(arr[nx][ny]==0)
                {
                    bfs.push({nx, ny});
                    arr[nx][ny]=arr[x][y]+1;
                }
            }
        }
    }

    int days=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(arr[i][j]==0)
            {
                printf("-1");
                return 0;
            }
            else
                days=max(days,arr[i][j]);
    
    printf("%d", days-1);
}