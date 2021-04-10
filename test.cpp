
#include<iostream>
#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;

const int way[8][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};

int main(void)
{
    int t; scanf("%d", &t);
    int arr[300][300];
    queue<pair<int,int> > bfs;
    for(int z=0; z<t; z++)
    {
        while(!bfs.empty())
            bfs.pop();
        memset(arr,0,sizeof(int)*300*300);
        // 초기화
        int i,st_x,st_y,tar_x,tar_y; 
        scanf("%d%d%d%d%d", &i,&st_x,&st_y,&tar_x,&tar_y);
        bfs.push({st_x, st_y});
        arr[st_x][st_y]=1;

        while(bfs.front().first!=tar_x || bfs.front().second!=tar_y)
        {
            pair<int,int> now=bfs.front();
            bfs.pop();
            for(int w=0; w<8; w++)
            {
                int nx=now.first+way[w][0], ny=now.second+way[w][1];
                if(nx>=0 && nx<i && ny>=0 && ny<i)
                    if(arr[nx][ny]==0)
                    {
                        bfs.push({nx,ny});
                        arr[nx][ny]=arr[now.first][now.second]+1;
                    }
            }
        }
        printf("%d\n", arr[bfs.front().first][bfs.front().second]-1);
    }
    return 0;
}