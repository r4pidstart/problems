// https://www.acmicpc.net/problem/7576
// 2021-04-11 10:11:52 128ms
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))

const int way[6][3] = {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,1}, {0,0,-1}};

int main(void)
{
    int m,n,h; scanf("%d%d%d", &m,&n,&h);
    int arr[h][n][m]={};
    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                scanf("%d", &arr[k][i][j]);

    queue<tuple<int,int,int>> bfs;
    int count=0;
    for(int k=0; k<h; k++)
        for(int i=0; i<m*n; i++)
            if(arr[k][i/m][i%m]==1)
            {
                bfs.push({k,i/m,i%m});
                count++;
            }
    
    if(count==0)
    {
        printf("-1");
        return 0;
    }

    while(!bfs.empty())
    {
        int x=get<1>(bfs.front()), y=get<2>(bfs.front()), z=get<0>(bfs.front());
        bfs.pop();
        for(int w=0; w<6; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1], nz=z+way[w][2];
            if(nx>=0 && nx<n && ny>=0 && ny<m && nz>=0 && nz<h)
            {
                if(arr[nz][nx][ny]==0)
                {
                    bfs.push({nz, nx, ny});
                    arr[nz][nx][ny]=arr[z][x][y]+1;
                }
            }
        }
    }

    int days=0;
    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(arr[k][i][j]==0)
                {
                    printf("-1");
                    return 0;
                }
                else
                    days=max(days,arr[k][i][j]);
    
    printf("%d", days-1);
}