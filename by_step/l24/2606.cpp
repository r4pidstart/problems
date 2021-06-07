// https://www.acmicpc.net/problem/2606
// 2021-04-08 01:00:41 0ms
#include<iostream>
#include<queue>
using namespace std;

int point[101]={};
int arr[101][101]={};

int bfs(int start, int n)
{
    queue<int> bfs;
    bfs.push(start);
    point[start]=1;
    int count=0;
    while(!bfs.empty())
    {
        int now=bfs.front();
        bfs.pop();
        for(int i=1; i<=n; i++)
            if(point[i]!=true && arr[now][i]==1)
            {
                bfs.push(i);
                point[i]=1;
                count++;
            }
    }
    return count;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    
    for(int i=0; i<m; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        arr[x][y] = arr[y][x] = 1;
    }
    
    printf("%d", bfs(1,n));

}