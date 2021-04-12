// https://www.acmicpc.net/problem/2206
// 2021-04-12 23:16:28 84ms
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

const int way[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    int arr[n][m], visited[n][m][2]={};
    getchar(); // remove \n
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            arr[i][j]=getchar();
        getchar();
    }

    queue< tuple<int,int,int> > bfs;
    bfs.push({0,0,0});
    visited[0][0][0]=1;

    while(get<0>(bfs.front())!=n-1 || get<1>(bfs.front())!=m-1)
    {
        if(bfs.empty())
        {
            printf("-1");
            return 0;
        }
        int x=get<0>(bfs.front()), y=get<1>(bfs.front()), flag=get<2>(bfs.front());
        bfs.pop();
        for(int w=0; w<4; w++)
        {
            int nx=x+way[w][0], ny=y+way[w][1];
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(arr[nx][ny]=='0') // 벽이 아닐 때
                {
                    if(visited[nx][ny][flag]==0)
                    {
                        bfs.push({nx,ny,flag});
                        visited[nx][ny][flag]=visited[x][y][flag]+1;
                    }
                }
                else // 벽일 때
                {
                    if(flag==0)
                    {
                        bfs.push({nx,ny,1});
                        visited[nx][ny][1]=visited[x][y][0]+1;
                    }
                }
            }
        }
    }
    if(visited[n-1][m-1][0])
        printf("%d", visited[n-1][m-1][0]);
    else
        printf("%d", visited[n-1][m-1][1]);
    return 0;
}